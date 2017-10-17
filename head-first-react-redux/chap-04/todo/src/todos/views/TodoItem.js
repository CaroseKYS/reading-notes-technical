import React from 'react';

const TodoItem = ({onToggle, onRemove, completed, text}) => (
  <li className="todo-item"
      style={
        {textDecoration: completed? 'line-through' : 'none'}
      }>

    <input type="checkbox" className="toggle" 
      checked={completed? 'checked' : ''} readOnly onClick={onToggle}/>

    <label className="text">{text}</label>

    <button className="remove" onClick={onRemove}>×</button>
  </li>
);

export default TodoItem;