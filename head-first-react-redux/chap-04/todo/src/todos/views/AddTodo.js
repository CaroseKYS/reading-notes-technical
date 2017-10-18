import React, {Component} from 'react';
import {connect} from 'react-redux';
import {addTodo} from '../actions.js';

class AddTodo extends Component{

  constructor(props) {
    super(props);
    this.onSubmit = this.onSubmit.bind(this);
    this.onInputChange = this.onInputChange.bind(this);

    this.state = {
      value: ''
    };
  }

  render() {
    return (
      <div className="add-todo">
        <form onSubmit={this.onSubmit}>
          <input type="text" className="new-todo" onChange={this.onInputChange} value={this.state.value}/>
          <button className="add-btn" type="submit">添加</button>
        </form>
      </div>
    );
  }

  onSubmit(e){
    e.preventDefault();

    let value = this.state.value;

    if (!value.trim()) {
      return;
    }

    this.props.onAdd(value);
    
    this.setState({
      value: ''
    });
  }

  onInputChange(e){
    let value = e.target.value;
    this.setState({value});
  }
}

const mapDispatchToProps = (dispatch, ownProps) => ({
  onAdd(value){
    dispatch(addTodo(value));
  }
});

export default connect(null, mapDispatchToProps)(AddTodo);