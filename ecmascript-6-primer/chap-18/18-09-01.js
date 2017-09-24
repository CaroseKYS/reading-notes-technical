class Birds{
  fly(){
    console.log('I can fly.');
  }
}

class Beast{
  run(){
    console.log('I can run.');
  }
}

class Dragon extends mix(Birds, Beast){

}

// console.log(Reflect.ownKeys(Beast.prototype));

var dragon = new Dragon();

dragon.fly();
dragon.run();

function mix(...mixins) {
  class Mix{}

  for (let mixin of mixins) {
    copyProperties(Mix, mixin);
    copyProperties(Mix.prototype, mixin.prototype);
  }

  return Mix;
}

function copyProperties(target, source) {
  let desc;
  for (let prop of Reflect.ownKeys(source)) {
    if (prop === 'constructor' || prop === 'name' || prop === 'prototype') {
      continue;
    }

    desc = Object.getOwnPropertyDescriptor(source, prop);

    Object.defineProperty(target, prop, desc);
  }
}