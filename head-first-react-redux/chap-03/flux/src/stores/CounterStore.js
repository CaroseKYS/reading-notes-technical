import AppDispatcher from '../AppDispatcher.js';
import * as ActionTypes from '../ActionTypes.js';
import {EventEmitter} from 'events';

const CHANGE_EVENT = 'change';

const counterValues = {
  First: 0,
  Second: 10,
  Third: 30
};

const CounterStore = Object.assign({}, EventEmitter.prototype, {
  getCounterValues(){
    return counterValues;
  },

  emitChange(){
    this.emit(CHANGE_EVENT);
  },

  addChangeListener(callback){
    this.on(CHANGE_EVENT , callback);
  },

  removeChangeListener(callback){
    this.removeListener(CHANGE_EVENT, callback);
  }

});

CounterStore.dispatchToken = AppDispatcher.register(action => {
  switch(action.type){
    case ActionTypes.INCREMENT:
      counterValues[action.counterCaption] ++;
      CounterStore.emitChange();
      break;
    case ActionTypes.DECREMENT:
      counterValues[action.counterCaption] --;
      CounterStore.emitChange();
      break;
  }
});

export default CounterStore;