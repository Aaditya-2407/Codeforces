import React from 'react'
import {useState} from 'react';
import "../style.css"

function Counter() {
    const [count, setCount] = useState(0);
  return (
    <div className='container'>
        <div><h1 className='number'>{count}</h1></div>
        <div className="btn-container">
        <button className="increment" onClick={() => setCount(count + 1)}>Increment</button>
        <button className="increment" onClick={() => setCount(count - 1)}>Decrement</button>
        </div>
    </div>
  )
}

export default Counter
