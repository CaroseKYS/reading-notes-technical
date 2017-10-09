import React, {Component} from 'react';
import store from '../Store.js';
import * as Actions from '../Actions.js';

class Counter extends Component{

  constructor(props){
    super(props);

    this.getOwnState         = this.getOwnState.bind(this);
    this.onChange            = this.onChange.bind(this);
    this.onClickIncrementBtn = this.onClickIncrementBtn.bind(this);
    this.onClickDecrementBtn = this.onClickDecrementBtn.bind(this);
    
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

  onClickIncrementBtn(){
    store.dispatch(Actions.increment(this.props.caption));
  }

  onClickDecrementBtn(){
    store.dispatch(Actions.decrement(this.props.caption));
  }

  render(){
    const {caption} = this.props;
    return (
      <div>
        <button onClick={this.onClickIncrementBtn}>+</button>
        <span>  </span>
        <button onClick={this.onClickDecrementBtn}>-</button>
        <span>    {caption} count: {this.state.value}</span>
      </div>
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