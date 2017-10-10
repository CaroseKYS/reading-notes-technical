import React, {Component} from 'react';
import {connect} from 'react-redux';

class Summary extends Component{
  render(){
    return (
      <div>
        Summary: {this.props.sum}
      </div>
    );
  }
};

export default connect(mapStateToProps, mapDispatchToProps)(Summary);

function mapStateToProps(state, ownProps) {
  let sum = 0;

  for (let key in state) {
    if (state.hasOwnProperty(key)) {
      sum += state[key];
    }
  }
  
  return {sum};
}

function mapDispatchToProps() {}