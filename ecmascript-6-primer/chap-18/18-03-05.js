class MyClass{
  constructor(){

  }

  get prop(){
    return 'getter';
  }

  set prop(value){
    console.log('setter: ', value);
  }
}

var inst = new MyClass();

inst.prop = 123;

console.log(inst.prop);

console.log('---------------');

class CustomHTMLElement{
  constructor(){
    this.element = element;
  }

  get html(){
    return this.element.innerHtml;
  }

  set html(value){
    this.element.innerHtml = value;
  }
}

var descriptor = Object.getOwnPropertyDescriptor(CustomHTMLElement.prototype, 'html');

console.log('get' in descriptor);
console.log('set' in descriptor);