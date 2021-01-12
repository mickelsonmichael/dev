# Redux Notes

This will be a repository containing my notes on what Redux is, as well as a practice application that I can use to test my knowledge.

## Definitions

An **Action** is a JavaScript object that contains a type. Similar to an event that describes what just happened in the application. Generally, the type is written in the format "{feature}/{event}"; for example, "counter/increment".

```js
// the basic action definition
{
    type: string,
    payload: any
}
```

Actions can be created manually, but it is generally best practice to use an **Action Creator**, which is just a simple function that returns an action.

```js
// action creator with no payload
const increment = () => { type: "counter/increment" };

// action creator WITH a payload
const set = (num) => { type: "counter/set", payload: num };
```

Actions are passed into **Reducers** along with the current state. They then perform some logic and return a new, updated version of the state. They are like event listeners that respond to different actions based on the type. **They get their name from the `Array.reduce` method**. They have three rules

- Must only calculate the new state based on the action and the type; not exterior information. This makes them easily testable and more predictable
- Must not modify state, instead should return a new, updated copy of the state
- Must not do any of the following:
  - Async logic
  - Calculate random values (would ruin the testability)
  - Cause other side-effects which can lead to hard-to-find bugs

Reducers don't always necessarily have to do anything with a particular action. It may be the case that they _don'T handle the action type provided and simply return the unmodified state_.

```js
const counterReducer = (state, action) => {
  if (action.type === "counter/increment")
    return { ...state, count: state.count + 1 };

  if (action.type === "counter/set") return { ...state, count: action.payload };

  return state; // doesn't handle the type
};
```

The current application state is found within the **Store**. You can easily create a new store using the `configureStore` method.

```js
import { configureStore } from "@reduxjs/tookit";

const store = configureStore({ reducer: counterReducer });
```

There is also the concept of a **Root Reducer**; a root reducer is the reducer that is called automatically by `configureStore` when the store is first initialized. Since there is no type provided, the reducer should return the default application state, which the `configureStore` method will then use as the initial state. In order to generate this reducer, the `configureStore` method calls the `combineReducers` method, which will create the root reducer for us without us having to do it manually.

```js
// manual root reducer
const manualRoot = (state = {}, action) => ({
  sliceA: sliceAReducer,
  sliceB: sliceBReducer,
});

// automatic root reducer
const autoRoot = combineReducers({
  sliceA: sliceAReducer,
  sliceB: sliceBReducer,
});

// manually set root
const manualStore = configureStore({
  reducer: autoRoot,
});

// automatically set root
const autoStore = configureStore({
  reducer: {
    sliceA: sliceAReducer,
    sliceB: sliceBReducer,
  },
});
```

When you want to get the current value(s) of the store, you can call `getState` on the store itself.

```js
store.getState(); // current state of the store
```

The store also contains a method called the **Dispatch**. In order to update the store, you need to call the `dispatch()` method and pass it an action object. It is similar to triggering an event. While typically an **action creator** is used, you could instead create the action manually and dispatch it.

```js
const action = incrementAction(); // use an action creator

store.dispatch(action); // update the store
```

While `getState` retrieves the entire state, we can use **Selectors** to get only a specific part of that state. They are similar to an `Array.map` call in concept, in that they distill down the entire state into only the section we are concerned with.

```js
const selectCount = (state) => state.count;

const count = selectCount(store.getState());
```

Stores are broken down into individual **Slices**. A slice is responsible for a particular feature of an application, containing the reducers and actions for that particular portion.
