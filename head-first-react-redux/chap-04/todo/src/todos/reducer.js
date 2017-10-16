import {ADD_TODO, REMOVE_TODO, TOGGLE_TODO} from './actionTypes.js';

export default (state = [], action) => {
  switch(action.type){
    case ADD_TODO:
      return [{
        id  : action.id,
        text: action.text,
        completed: false
      }, ...state];
    case REMOVE_TODO: 
      return state.filter(todo => todo.id !== action.id);
    case TOGGLE_TODO:
      return state.map(todo => {
        if (todo.id === action.id) {
          return {
            ... todo,
            completed: !todo.completed
          };
        }else{
          return todo;
        }
      });
    default:
      return state;
  }
};