class Foo{
  constructor(...args){
    this.args = args;
  }

  *[Symbol.iterator](){
    for (let arg of this.args) {
      yield arg;
    }
  }

  static classMethod(){
    console.log('Hello World');
  }
}

for(let x of new Foo('hello', 'world')){
  console.log(x);
}

Foo.classMethod();

console.log('classMethod' in (new Foo()));