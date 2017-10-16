import React, {Component} from 'react';
import {connect} from 'react-redux';
import {addTodo} from 'react';

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
          <button className="add-btn" type="submit">提交</button>
        </form>
      </div>
    );
  }

  onSubmit(e){
    e.preventDefault();

    const input = this.input.value;

    if (!input.trim()) {
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
    dispatch(value);
  }
});

export default connect(null, )(AddTodo);