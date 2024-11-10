const express = require('express');
const path = require('path');
const ffi = require('ffi-napi');
const ref = require('ref-napi');
const WebSocket = require('ws'); // 引入 ws 模块

const app = express();
const port = 3000;

const LCD_WIDTH = 800;
const LCD_HEIGHT = 480;

// 加载静态文件，如 index.html 和前端的 JavaScript
app.use(express.static(path.join(__dirname, 'public')));

// 定义 uint16_t 类型（16位无符号整型）
const uint16_t = ref.types.uint16;

const uint8_t = ref.types.uint8; 

// 定义 fb_buf 的指针类型
const fb_buf_type = ref.refType(uint16_t);  

// 加载动态库（确保路径正确）
const libPath = './liblvgl.so';

// 更新 lvglLib 定义以包括新的 C 函数
const lvglLib = ffi.Library(libPath, {
  'app_restart': ['void',['string']],
  'lvgl_init': ['void', ['string']],
  'lvgl_update_fb': [ref.types.uint8, [fb_buf_type]],
  'update_mouse_state': ['void', [ref.types.uint16, ref.types.uint16, ref.types.uint8]],  // 新增更新鼠标状态的函数
});

// 初始化 lvgl
lvglLib.lvgl_init(path.join(__dirname, 'fat_product.img'));

// 创建一个空的缓冲区用于存储 fb_buf
let fb_buf = Buffer.alloc(LCD_WIDTH * LCD_HEIGHT * 2);  // 320x240 的 16 位 RGB565 图像 
// 创建 WebSocket 服务器
const wss = new WebSocket.Server({ noServer: true });

wss.on('connection', (ws) => {
    console.log('Client connected start');
    
    lvglLib.app_restart("test");

    // 定期发送 framebuffer 数据
    const sendFramebuffer = () => { 
        if (lvglLib.lvgl_update_fb(fb_buf))
        {
           ws.send(fb_buf); // 发送缓冲区数据 
        } 
    };

    const intervalId = setInterval(sendFramebuffer, 20);

    ws.on('close', () => {
        console.log('Client disconnected');
        clearInterval(intervalId); // 清除定时器 
    });

    ws.on('message', (message) => {
        const { x, y, state } = JSON.parse(message);

        if (typeof x === 'number' && typeof y === 'number' && (state === 0 || state === 1) &&
            (x >= 0 && x < LCD_WIDTH) && (y >= 0 && y < LCD_HEIGHT)) {
            // Call the C function to update the mouse state
            lvglLib.update_mouse_state(x, y, state);
        } else {
            lvglLib.update_mouse_state(0, 0, 0);
        }
    });
});

// 将 WebSocket 服务器与 Express 服务器结合
const server = app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});

server.on('upgrade', (request, socket, head) => {
    wss.handleUpgrade(request, socket, head, (ws) => {
        wss.emit('connection', ws, request);
    });
});

// 设置根路径返回 index.html
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, '.', 'index.html'));
});

app.get('/lcd_bg.png', (req, res) => {
    res.sendFile(path.join(__dirname, '.', 'stm32f469_lizard_black.png'));
});