import * as ActionTypes from './ActionTypes.js';

export default (state, action) => {
  const {counterCaption} = action;
  let newState;

  switch(action.type){
    case ActionTypes.INCREMENT:
      newState = {... state, [counterCaption]: state[counterCaption] + 1};
    case ActionTypes.DECREMENT:
      newState = {... state, [counterCaption]: state[counterCaption] - 1};
      break;
    default:
      newState = state;
  }

  console.log(newState);
  return newState;
};