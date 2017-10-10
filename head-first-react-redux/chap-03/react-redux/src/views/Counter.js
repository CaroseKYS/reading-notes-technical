import React, {Component} from 'react';
import * as Actions from '../Actions.js';
import {connect} from 'react-redux';

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

export default connect(mapStateToProps, mapDispatchToProps)(Counter);

function mapStateToProps(state, ownProps) {
  return {
    value: state[ownProps.caption]
  };
}

function mapDispatchToProps(dispatch, ownProps) {
  return {
    onIncrement(){
      dispatch(Actions.increment(ownProps.caption));
    },

    onDecrement(){
      dispatch(Actions.decrement(ownProps.caption));
    }
  };
}