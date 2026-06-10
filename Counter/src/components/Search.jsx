import React from 'react'
import { useState } from 'react';
import { FaSearch } from 'react-icons/fa';
import "../Search.css";

function Search() {
    const [showInput, setShowInput] = useState(false);
    const [bgColor, setBgColor] = useState("white");



    const handleClick = (e) => {
        setBgColor(bgColor === "white" ? "#1b1b1b" : "white");
        if(e.target.className === "container")
        {
            setShowInput(false);
            setBgColor("white");
            setBgColor("#fff");

        }
    }
  return (
    <section
    className="container"
    style={{ backgroundColor: bgColor }}
    onClick={handleClick}>
        {showInput ? (
            <input type = "text" placeholder="Search..."/>
        ): (<FaSearch size={50} color={bgColor === "white" ? "#1b1b1b" : "white"} className="search-icon" onClick={() => setShowInput(true)}/>)
    }
    </section>
  )
}

export default Search
