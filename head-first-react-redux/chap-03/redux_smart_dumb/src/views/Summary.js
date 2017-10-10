import React, {Component} from 'react';
import store from '../Store.js';
import SummaryDumb from './SummaryDumb';

class Summary extends Component{

  constructor(props){
    super(props);

    this.onChange    = this.onChange.bind(this);
    this.getOwnState = this.getOwnState.bind(this);

    this.state = this.getOwnState();
  }

  getOwnState(){
    let state = store.getState();
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
    store.subscribe(this.onChange);
  }

  componentWillUnmount(){
    store.unsubscribe(this.onChange);
  }
};

export default Summary;