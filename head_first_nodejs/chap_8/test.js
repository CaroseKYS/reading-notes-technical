var http = require('http');
var url = require('url');
var fs = require('fs');
http.createServer(function(req, res){
  res.writeHead(200, {'Content-Type': 'text/html'});
  var stream = fs.createReadStream('./test.html');
  stream.on('data', function(data){
    console.log("new data: ",data);
    res.write(data);
  });

  stream.on('end', function(){
    res.end();
  });
  
  //stream.pipe(res);
}).listen(1337);
