var events = require('events');
var util = require('util');

function MyEmitter(){
  events.EventEmitter.call(this);
}

util.inherits(MyEmitter, events.EventEmitter);

module.exports = MyEmitter;
