import AppDispatcher from '../AppDispatcher.js';
import * as ActionTypes from '../ActionTypes.js';
import {EventEmitter} from 'events';
import CounterStore from './CounterStore.js';

const CHANGE_EVENT = 'change';

const SummaryStore = Object.assign({}, EventEmitter.prototype, {
  getSummary(){
    return computeSummary(CounterStore.getCounterValues())
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

SummaryStore.dispatchToken = AppDispatcher.register(action => {
  switch(action.type){
    case ActionTypes.INCREMENT:
    case ActionTypes.DECREMENT:
      AppDispatcher.waitFor([CounterStore.dispatchToken]);
      SummaryStore.emitChange();
      break;
  }
});

function computeSummary(values) {
  let sum = 0;
  for (let key in values) {
    if (values.hasOwnProperty(key)) {
      sum += values[key];
    }
  }

  return sum;
}

export default SummaryStore;