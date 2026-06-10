import React from 'react'
import { useState, useEffect} from 'react';
import "../style.css"

function Calculator() {
    const [inputvalue, setinputvalue] = useState([]);

    function display(value){
        setinputvalue(inputvalue + value);
    }

    function calculate(){
        var answer = eval(inputvalue);
        setinputvalue(answer);
    }
    function clear(){
        setinputvalue("");
    }

  return (
    <div>
        <form class="calculator" name="calc">
            <input type="text" className="value" value={inputvalue} />
            <span className="num clear" onClick={() => clear()}>C</span>
            <span className="num" onClick={()=>display("/")}>/</span>
            <span className="num" onClick={()=>display("*")}>*</span>
            <span className="num" onClick={()=>display("7")}>7</span>
            <span className="num" onClick={()=>display("8")}>8</span>
            <span className="num" onClick={()=>display("9")}>9</span>
            <span className="num" onClick={()=>display("-")}>-</span>
            <span className="num" onClick={()=>display("4")}>4</span>
            <span className="num" onClick={()=>display("5")}>5</span>
            <span className="num" onClick={()=>display("6")}>6</span>
            <span className="num" onClick={()=>display("+")}>+</span>
            <span className="num" onClick={()=>display("1")}>1</span>
            <span className="num" onClick={()=>display("2")}>2</span>
            <span className="num" onClick={()=>display("3")}>3</span>
            <span className ="num equal"onClick={()=>calculate()}>=</span>
        </form>
      
    </div>
  );
}

export default Calculator
