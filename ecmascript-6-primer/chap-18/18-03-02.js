class MyArray extends Array{
  constructor(...args){
    super(...args);
  }
}

var arr = new MyArray();

arr[0] = 12;
console.log(arr.length);

arr.length = 0;
console.log(arr[0]);