import "./App.css";
import { useState } from "react";

function App() {
  const [counter, setCounter] = useState(0);

  const increment = () => setCounter((prev) => prev + 1);
  const decrement = () => setCounter((prev) => prev - 1);

  return [
    <button type="button" onClick={decrement}>
      -
    </button>,
    <strong>{counter}</strong>,
    <button type="button" onClick={increment}>
      +
    </button>,
  ];
}

export default App;
