var http = require('http');
http.createServer(function(){
  res.writeHead(100, {'Content-Type': 'text/plain'});
  res.end('Hello World.\n');
}).listen(Math.round((1 + Math.random()) * 1000));
