import { useDispatch, useSelector } from "react-redux";
import { getCount, increment, decrement } from "./counterSlice";

const Counter = () => {
  const dispatch = useDispatch();
  const count = useSelector(getCount);

  return [
    <button key={"dec"} type="button" onClick={() => dispatch(decrement())}>
      -
    </button>,
    <strong key={"cnt"}>{count}</strong>,
    <button key={"inc"} type="button" onClick={() => dispatch(increment())}>
      +
    </button>,
  ];
};

export default Counter;
