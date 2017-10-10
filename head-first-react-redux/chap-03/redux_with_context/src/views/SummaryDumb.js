import React, {Component} from 'react';

class SummaryDumb extends Component{
  render(){
    return (
      <div>
        Summary: {this.props.sum}
      </div>
    );
  }
};

export default SummaryDumb;