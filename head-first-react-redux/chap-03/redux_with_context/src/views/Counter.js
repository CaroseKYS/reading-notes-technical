import React, {Component} from 'react';
import {PropTypes} from 'prop-types';
import * as Actions from '../Actions.js';
import CounterDumb from './CounterDumb.js';
console.log(PropTypes);

class Counter extends Component{

  constructor(props, context){
    super(props, context);

    this.getOwnState = this.getOwnState.bind(this);
    this.onChange    = this.onChange.bind(this);
    this.onIncrement = this.onIncrement.bind(this);
    this.onDecrement = this.onDecrement.bind(this);
    
    this.state = this.getOwnState();
  }

  getOwnState(){
    return {
      value: this.context.store.getState()[this.props.caption]
    };
  }

  onChange(){
    this.setState(this.getOwnState());
  }

  onIncrement(){
    console.log('in onIncrement');
    this.context.store.dispatch(Actions.increment(this.props.caption));
  }

  onDecrement(){
    console.log('in onDecrement');
    this.context.store.dispatch(Actions.decrement(this.props.caption));
  }

  render(){
    const {caption} = this.props;
    return (
      <CounterDumb caption={caption} value={this.state.value} onIncrement={this.onIncrement} onDecrement={this.onDecrement} />
    );
  }

  componentDidMount(){
    this.context.store.subscribe(this.onChange);
  }

  componentWillUnmount(){
    this.context.store.unsubscribe(this.onChange);
  }
};

Counter.contextTypes = {
  store: PropTypes.Object
};

export default Counter;