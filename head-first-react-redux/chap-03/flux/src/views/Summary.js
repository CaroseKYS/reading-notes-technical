import React, {Component} from 'react';
import SummaryStore from '../stores/SummaryStore.js';
import * as Actions from '../Actions.js';

class Counter extends Component{

  constructor(props){
    super(props);
    this.state = {
      sum:  SummaryStore.getSummary()
    };

    this.onChange = this.onChange.bind(this);
  }

  onChange(){
    this.setState({sum: SummaryStore.getSummary()});
  }

  render(){
    const {caption} = this.props;
    return (
      <div>
        Summary: {this.state.sum}
      </div>
    );
  }

  componentDidMount(){
    SummaryStore.addChangeListener(this.onChange);
  }

  componentWillUnmount(){
    SummaryStore.removeChangeListener(this.onChange);
  }
};

export default Counter;