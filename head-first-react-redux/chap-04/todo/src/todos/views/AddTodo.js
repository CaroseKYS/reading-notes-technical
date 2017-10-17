import React, {Component} from 'react';
import {connect} from 'react-redux';
import {addTodo} from '../actions.js';

class AddTodo extends Component{

  constructor(props) {
    super(props);
    this.onSubmit = this.onSubmit.bind(this);
    this.refInput = this.refInput.bind(this);
  }

  render() {
    return (
      <div className="add-todo">
        <form onSubmit={this.onSubmit}>
          <input type="text" className="new-todo" ref={this.refInput}/>
          <button className="add-btn" type="submit">添加</button>
        </form>
      </div>
    );
  }

  onSubmit(e){
    e.preventDefault();

    const input = this.input;

    if (!input.value.trim()) {
      return;
    }

    this.props.onAdd(input.value);
    input.value = '';
  }

  refInput(node){
    this.input = node;
  }
}

const mapDispatchToProps = (dispatch, ownProps) => ({
  onAdd(value){
    dispatch(addTodo(value));
  }
});

export default connect(null, mapDispatchToProps)(AddTodo);