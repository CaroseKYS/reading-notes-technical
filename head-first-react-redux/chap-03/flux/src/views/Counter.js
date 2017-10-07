import React, {Component} from 'react';
import PropTypes from 'prop-types';
import CounterStore from '../stores/CounterStore.js';
import * as Actions from '../Actions.js';

class Counter extends Component{

  constructor(props){
    super(props);
    this.state = {
      count:  CounterStore.getCounterValues()[this.props.caption]
    };

    this.onChange            = this.onChange.bind(this);
    this.onClickIncrementBtn = this.onClickIncrementBtn.bind(this);
    this.onClickDecrementBtn = this.onClickDecrementBtn.bind(this);
  }

  onChange(){
    const newCount = CounterStore.getCounterValues()[this.props.caption];
    this.setState({count: newCount});
  }

  onClickIncrementBtn(){
    Actions.increment(this.props.caption);
  }

  onClickDecrementBtn(){
    Actions.decrement(this.props.caption);
  }

  render(){
    const {caption} = this.props;
    return (
      <div>
        <button onClick={this.onClickIncrementBtn}>+</button>
        <span>  </span>
        <button onClick={this.onClickDecrementBtn}>-</button>
        <span>    {caption} count: {this.state.count}</span>
      </div>
    );
  }

  componentDidMount(){
    CounterStore.addChangeListener(this.onChange);
  }

  componentWillUnmount(){
    CounterStore.removeChangeListener(this.onChange);
  }
};

Counter.propTypes = {
  caption: PropTypes.string.isRequired,
  initValue: PropTypes.number
};

export default Counter;