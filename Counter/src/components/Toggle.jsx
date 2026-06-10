import React from 'react'
import "../style.css";
import { useState } from 'react';

function Toggle() {
    const [backgroundColor, setbackgroundColor] = useState("white");
    const [textColor, settextColor] = useState("black");
    const [buttonStyle, setbuttonStyle] = useState("black");

    function handleClick(){
        setbackgroundColor (backgroundColor === "white" ? "#1b1b1b" : "white");
        settextColor (textColor === "black" ? "#ffa31a" : "#black");
        setbuttonStyle (buttonStyle === "#ffa31a" ? "#1b1b1b" : "#ffa31a");
    }

  return (
    <div>
        <section style={{ backgroundColor, color: textColor }}>
            <button onClick={handleClick}
            style={{ buttonStyle: buttonStyle, color: textColor,
                border: `2px solid ${textColor}`,
            }}>
                {backgroundColor === "#1b1b1b" ? "Light Mode" : "Dark Mode"}


                </button> 
                <section className="content">
                    <h1>Toggle Component</h1>
                    <p>This is a simple toggle component that allows you to switch between light and dark modes. Click the button above to see the effect!</p>

                </section>
                </section>
      
    </div>
  );
}

export default Toggle;
