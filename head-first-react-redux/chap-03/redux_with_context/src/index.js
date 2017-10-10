import React from 'react';
import ReactDOM from 'react-dom';
import store from './Store.js';
import './index.css';
import ControlPanel from './views/ControlPanel';
import Provider from './views/Provider';

ReactDOM.render(
  <Provider store={store}>
    <ControlPanel />
  </Provider>, 
  document.getElementById('root')
);
