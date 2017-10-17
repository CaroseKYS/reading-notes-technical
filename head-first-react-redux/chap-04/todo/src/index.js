import React from 'react';
import ReactDOM from 'react-dom';
import {Provider} from 'react-redux';
import store from './Store.js';
import TodoApp from './TodoApp.js';
import './index.css';

ReactDOM.render(
  <Provider store={store}>
    <TodoApp />
  </Provider>, 
  document.getElementById('root')
);
