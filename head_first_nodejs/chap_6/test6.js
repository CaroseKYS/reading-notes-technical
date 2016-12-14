/**
 * 测试buffer拼接
 */

var fs = require('fs');
var rs = fs.createReadStream('./test4.md', {
  highWaterMark: 5
});/*此处不能设置编码，否则会直接解码*/

var bufs = [];
var size = 0;

rs.on('data', function(chunk){
  console.log('chunk: ', chunk);
  bufs.push(chunk);
  size += chunk.length;
});

rs.on('end', function(){
  var result = Buffer.concat(bufs, size);
  console.log('size: ', size, ', content: ', result.toString('utf8'));
});