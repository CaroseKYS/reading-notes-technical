var http = require('http');
var hasBody = function(req){
  return 'transfer-encoding' in req.headers || 'content-length' in req.headers;
};

var server = http.createServer(function(){
  if(hasBody(req)){
    var buffers = [];
    req.on('data', function(chunk){
      buffers.push(chunk);
    });

    req.on('end', function(){
      req.rawBody = Buffer.concat(buffers).toString();
      handle(req, res);
    });
  }else{
    handle(req, res);
  }

});

server.listen(1337, function(){
  console.log('Server started at 1337.');
});
