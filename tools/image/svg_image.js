const fs = require('fs');
const xml2js = require('xml2js');
 
// 读取SVG文件
fs.readFile('extruder.svg', 'utf8', (err, data) => {
  if (err) {
    console.error(err);
    return;
  }
 
  // 解析SVG XML
  xml2js.parseString(data, { trim: true }, (parseError, result) => {
    if (parseError) {
      console.error(parseError);
      return;
    }
 
    // 获取SVG根元素的属性
    const svg = result.svg;
    const width = svg.width;
    const height = svg.height;
 
    console.log('Width:', width);
    console.log('Height:', height);
  });
});