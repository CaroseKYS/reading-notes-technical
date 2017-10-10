import React, {Component} from 'react';
import {PropTypes} from 'prop-types';
import SummaryDumb from './SummaryDumb';

class Summary extends Component{

  constructor(){
    super(... arguments);

    this.onChange    = this.onChange.bind(this);
    this.getOwnState = this.getOwnState.bind(this);

    this.state = this.getOwnState();
  }

  getOwnState(){
    let state = this.context.store.getState();
    let sum = 0;

    for (let key in state) {
      if (state.hasOwnProperty(key)) {
        sum += state[key];
      }
    }
    
    return {sum};
  }

  onChange(){
    this.setState(this.getOwnState());
  }

  render(){
    return (<SummaryDumb sum={this.state.sum} />);
  }

  componentDidMount(){
    this.context.store.subscribe(this.onChange);
  }

  componentWillUnmount(){
    this.context.store.unsubscribe(this.onChange);
  }
};

Summary.contextTypes = {
  store: PropTypes.Object
};

export default Summary;