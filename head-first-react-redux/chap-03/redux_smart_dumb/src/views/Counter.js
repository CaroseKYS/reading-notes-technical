import React, {Component} from 'react';
import store from '../Store.js';
import * as Actions from '../Actions.js';
import CounterDumb from './CounterDumb.js';

class Counter extends Component{

  constructor(props){
    super(props);

    this.getOwnState = this.getOwnState.bind(this);
    this.onChange    = this.onChange.bind(this);
    this.onIncrement = this.onIncrement.bind(this);
    this.onDecrement = this.onDecrement.bind(this);
    
    this.state = this.getOwnState();
  }

  getOwnState(){
    return {
      value: store.getState()[this.props.caption]
    };
  }

  onChange(){
    this.setState(this.getOwnState());
  }

  onIncrement(){
    console.log('in onIncrement');
    store.dispatch(Actions.increment(this.props.caption));
  }

  onDecrement(){
    console.log('in onDecrement');
    store.dispatch(Actions.decrement(this.props.caption));
  }

  render(){
    const {caption} = this.props;
    return (
      <CounterDumb caption={caption} value={this.state.value} onIncrement={this.onIncrement} onDecrement={this.onDecrement}/>
    );
  }

  componentDidMount(){
    store.subscribe(this.onChange);
  }

  componentWillUnmount(){
    store.unsubscribe(this.onChange);
  }
};

export default Counter;