const express = require('express');
const path = require('path');
const ffi = require('ffi-napi');
const ref = require('ref-napi');
const http = require('http');   
const fs = require('fs');

const app = express();
const port = 3000; 

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

const server = app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
}); 

// 设置根路径返回 index.html
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, '.', 'index.html'));
});

app.get('/lcd_bg.png', (req, res) => {
    res.sendFile(path.join(__dirname, '.', 'stm32f469_lizard_black.png'));
});




class AppError extends Error {
    constructor(message, statusCode) {
        super(message);
        this.statusCode = statusCode;
        this.isOperational = true;
        Error.captureStackTrace(this, this.constructor);
    }
}

app.use(express.json({ limit: '10mb' }));

app.post('/generate', (req, res) => { 
    try { 
        //lvglLib.update_mouse_state(100,100,1);
        lvglLib.app_restart("ui task");

        res.send("hello");  
    } catch (error) {
        res.status(500).json({
            message: error.message || 'An unexpected error occurred',
            stack: error.stack
        });
    }
});
