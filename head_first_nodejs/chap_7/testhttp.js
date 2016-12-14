var http = require("http");

http.createServer(function(req, res){
  var buffer = [];
  req.on('data', function(chunk){
    buffer.push(chunk);
    //console.log(chunk);
  });

  req.on('end', function(){
    console.log(Buffer.concat(buffer).toString());
  });
  res.writeHead(200, {'Content-Type': 'text/plain'});
  console.log('----------' + 
                  req.method + " : " + req.url + " : " + req.httpVersion);
  res.write("Hello World.\n");
  res.end();
}).listen(1337);
console.log("server running.");

