var http = require("http");
var crypto = require("crypto");
var WebSocket = function(url){
  this.options = {
    protocolVersion: 13
  };
  this.connect();
};

WebSocket.prototype.onopen = function(){
  console.log("open");
  setInterval(function(){
    //this.socket.send("hahahaha");
  }, 1000);
};
WebSocket.prototype.setSocket = function(socket){
  this.socket = socket;
};

WebSocket.prototype.connect = function(){
  var that = this;
  var key = new Buffer(this.options.protocolVersion + '-' + Date.now()).toString('base64');
  var shasum = crypto.createHash("sha1");
  var expected = shasum.update(key + '258EAFA5-E914-47DA-95CA-C5AB-0DC85B11').digest('base64');
  var options = {
    port: 12010,
    host: '127.0.0.1',
    headers: {
      'Connection': 'Upgrade',
      'Upgrade': 'websocket',
      'Sec-WebSocket-Version': 13,
      'Sec-WebSocket-Key': key
    }
  };
  var req = http.request(options,function(res){
    res.on("data",function(data){
      console.log(data);
    });
  });
  req.end();

  req.on("upgrade", function(res, socket, upgradeHead){
    //console.log(socket);
    socket._send("hahaha");
    that.setSocket(socket);
    that.onopen();
  });
};

var socket = new WebSocket();
