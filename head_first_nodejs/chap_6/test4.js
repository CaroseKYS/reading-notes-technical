/**
 * 直接使用+拼接字符串
 */

var fs = require('fs');

// var rs = fs.createReadStream('test4.md');
var rs = fs.createReadStream('test4.md', {
  highWaterMark: 11
});

/*此行的作用是让data事件中传递的不再是一个Buffer对象，而是编码后的字符串
 *注销此行会产生乱码
*/
rs.setEncoding('utf-8');

var data = '';

rs.on('data', function(chunk){
  data += chunk;
});

rs.on('end', function(){
  console.log(data);
});