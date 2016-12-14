var http = require('http');
var crypto = require('crypto');
var sessions = {};
var secret = 'ksjfeipmxnmht52988639486isdseykskdfhdyeu965]][]\..';
var key = 'session_id';
var EXPIRES = 20 * 60 * 1000;

var sign = function(val, secret){
  return val + '.' + crypto.createHmac('sha256', secret).update(val).digest('base64').replace(/\=+$/, '');

};

var unsign = function(val, secret){
  var str = val.slice(0, val.lastIndexOf('.'));
  return sign(str, secret) == val ? str : false;
};

var passwd = sign('1234', secret);
console.log(passwd);

console.log(unsign(passwd, secret));

http.createServer(function(req, res){

})/*.listen(1337)*/;
