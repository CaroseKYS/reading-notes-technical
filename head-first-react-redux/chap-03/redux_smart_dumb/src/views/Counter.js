import React, {Component} from 'react';

class Counter extends Component{

  render(){
    const {caption, value, onIncrement, onDecrement} = this.props;
    return (
      <div>
        <button onClick={onIncrement}>+</button>
        <span>  </span>
        <button onClick={onDecrement}>-</button>
        <span>    {caption} count: {value}</span>
      </div>
    );
  }
};

export default Counter;