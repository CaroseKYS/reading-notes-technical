import React from 'react';
import AddTodo from './AddTodo.js';
import TodoList from './TodoList.js';

export default () => {
  return (
    <div className="todos">
      <AddTodo />
      <TodoList />
    </div>
  );
};