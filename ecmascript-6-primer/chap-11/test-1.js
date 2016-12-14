'use strict';

var obj = new Proxy({}, {
  get: function(target, key, receiver){
    console.log(`Getting ${key}`);
    return Reflect.get(target, key, receiver);
  },
  set: function(target, key, receiver){
    console.log(`Setting ${key}`);
    return Reflect.set(target, key, receiver);
  }
});

obj.count = 1;
++obj.count;