import React, {Component} from 'react';
import CounterContainer from './CounterContainer';
import Summary from './Summary';

class ControlPanel extends Component{
  render(){
    return (
      <div>
        <CounterContainer caption="First" />
        <CounterContainer caption="Second"/>
        <CounterContainer caption="Third" />
        <hr/>
        <Summary />
      </div>
    );
  }
}

export default ControlPanel;