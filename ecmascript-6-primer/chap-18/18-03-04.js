class ExtendableError extends Error{
  constructor(msg){
    super();
    this.message = msg;
    this.stack = (new Error()).stack;
    this.name = this.constructor.name;
  }
}

class MyError extends ExtendableError{
  constructor(msg){
    super(msg);
  }
}

var myerror = new MyError('ll');
console.log(myerror.message);
console.log(myerror instanceof Error);
console.log(myerror.name);
console.log(myerror.stack);