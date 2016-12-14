var http = require('http');
var hello = '';

for (var i = 0; i < 1024 * 10; i++) {
  hello += 'a';
}

/*注销改行即是以string的形式发送数据*/
hello = new Buffer(hello);

http.createServer(function(req, res){
  res.writeHead(200);
  res.end(hello);
}).listen(1338);