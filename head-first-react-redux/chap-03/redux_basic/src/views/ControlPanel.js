import React, {Component} from 'react';
import Counter from './Counter';
import Summary from './Summary';
const  initValues = [1, 2, 3];

class ControlPanel extends Component{
  constructor(props){
    super(props);
    this.onUpdate = this.onUpdate.bind(this);
    this.state = {
      sum: initValues.reduce((a, b) => a + b)
    };
  }

  onUpdate(newNum, oldNum){
    this.setState({sum: this.state.sum + (newNum - oldNum)}); 
  }

  render(){
    return (
      <div>
        <Counter caption="First"  onUpdate={this.onUpdate}/>
        <Counter caption="Second" onUpdate={this.onUpdate}/>
        <Counter caption="Third"  onUpdate={this.onUpdate}/>
        <hr/>
        <Summary />
      </div>
    );
  }
}

export default ControlPanel;