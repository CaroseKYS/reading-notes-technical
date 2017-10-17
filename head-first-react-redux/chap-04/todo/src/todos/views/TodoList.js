import React from 'react';
import {connect} from 'react-redux';
import TodoItem from './TodoItem.js';
import {toggleTodo, removeTodo} from '../actions.js';
import {FilterTypes} from '../../constants.js';

const TodoList = ({todos, onToggleTodo, onRemoveTodo}) => {
  return (
    <ul className="todo-list">
      {
        todos.map(item => (
          <TodoItem
            key={item.id}
            text={item.text}
            completed={item.completed} 
            onToggle={() => onToggleTodo(item.id)}
            onRemove={() => onRemoveTodo(item.id)} 
          />
        ))
      }
    </ul>
  );
};

const selectVisibleTodos = (todos, filter) => {
  switch (filter) {
    case FilterTypes.ALL:
      return todos;
      break;
    case FilterTypes.COMPLETED:
      return todos.filter(item => item.completed);
      break;
    case FilterTypes.UNCOMPLETED:
      return todos.filter(item => !item.completed);
      break;
    default:
      throw new Error('unsupported filter');
  }
};

const mapStateToProps = (state, ownProps) => ({
  todos: selectVisibleTodos(state.todos, state.filter)
});

const mapDispatchToProps = (dispatch, ownProps) => ({
  onToggleTodo: id => dispatch(toggleTodo(id)),
  onRemoveTodo: id => dispatch(removeTodo(id))  
});

export default connect(mapStateToProps, mapDispatchToProps)(TodoList);