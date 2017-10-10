import React, {Component} from 'react';

class Summary extends Component{
  render(){
    return (
      <div>
        Summary: {this.props.sum}
      </div>
    );
  }
};

export default Summary;