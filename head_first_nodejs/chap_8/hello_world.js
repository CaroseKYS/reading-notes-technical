var http = require('http');
http.createServer(function(req,res){
  //console.log(req.method);
  if(!req.headers.cookie){
    res.setHeader('Set-Cookie', "isVisit=1");
    res.writeHead(200, {'Content-Type': 'text/plain'});
    res.end('First Welcome....\n');
  }else{
    res.writeHead(200, {'Content-Type': 'text/plain'});
    res.end('Welcome again....\n');
  }
}).listen(1337);
console.log('server running at http://127.0.0.1:1337');

function serialize(name, value, opts){
  var pairs = [name + '=' + encode(value)];
}
console.log(encodeURIComponent);
