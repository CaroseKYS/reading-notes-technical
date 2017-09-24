class VersionedArray extends Array{
  constructor(){
    super();
    this.history = [];
  }

  commit(){
    this.history.push(this.slice());
  }

  revert(){
    this.splice(0, this.length, ...this.history[this.history.length - 1]);
  }

}

var x = new VersionedArray();

x.push(1);
x.push(2);
console.log('x: ', x);
console.log('x.history: ', x.history);

x.commit();
console.log('x.history: ', x.history);

x.push(3);
console.log('x: ', x);

x.revert();
console.log('x: ', x);