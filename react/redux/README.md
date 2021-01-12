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
