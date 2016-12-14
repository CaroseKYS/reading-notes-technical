/**
 * 字符串转buffer
 */

var str = '床前明月光，疑是地上霜。举头望明月，低头思故乡。'

// var buf = new Buffer(str, 'base64');
// console.log(buf);
// console.log(buf.toString('base64'));

// var buf = new Buffer(str, 'utf8');
// console.log(buf);
// console.log(buf.toString('utf8'));

// var buf = new Buffer(str, 'UTF-16LE');
// console.log(buf.length);
// console.log(buf.toString('UTF-16LE'));

var buf = new Buffer(str, 'UTF-8');
buf.write('飞流直下三千尺。', buf.length, 16, 'UTF-16LE');
console.log(buf.length);
console.log(buf.toString('UTF-8'));