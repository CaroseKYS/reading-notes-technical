var https = require('https');
var fs = require('fs');

var options = {
  key: fs.readFileSync('./keys/server.key'),
  cert: fs.readFileSync('./keys/server.crt')
};

https.createServer(options, function(req, res){
  res.writeHead(200, {'Content-Type': 'text/plain'});
  res.end('Hello world.\n');
}).listen(8000);
