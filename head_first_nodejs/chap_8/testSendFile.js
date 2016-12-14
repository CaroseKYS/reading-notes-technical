var sendfile = require('./sendfile');
var http = require("http");

http.createServer(function(req,res){
  sendfile(res, './test.js');
}).listen(1337);
