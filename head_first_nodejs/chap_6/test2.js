var buf = new Buffer(100);

console.log(buf.length);

console.log(buf[10]);

buf[10] = 100;
console.log(buf[10]);

buf[20] = -100;
console.log(buf[20]);

buf[30] = 355;
console.log(buf[30]);

buf[40] = 3.55;
console.log(buf[40]);

global.test = 'kangys';
console.log(test);