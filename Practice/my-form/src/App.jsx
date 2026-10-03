import { useState } from 'react'
import heroImg from './assets/hero.png'
import reactLogo from './assets/react.svg'
import viteLogo from './assets/vite.svg'
import './App.css'

function App() {
  const [name, setName] = useState("");
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [nameError, setNameError] = useState("");
const [emailError, setEmailError] = useState("");
const [passwordError, setPasswordError] = useState("");
function validateEmail(value) {
  const regex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
  return regex.test(value);
}
function validateName(value){
  if(value=="" || value==" "){
    return false;
  }
  else return true;
}
function validatepassword(value){
  if(value.length<6)
  {
    return false;
  }
  else return true;
}


  return (
    <>
      <h1>Form </h1>
      <input type="text"
      value={name}
      onChange={(e)=>{
        const value = e.target.value;
        setName(value)
        if(!validateName(value))
        {
          setNameError("Please enter valid name")
        }
        else{setNameError("")}
      }}
      placeholder='name' />
            {nameError && <p style={{ color: 'red' }}>{nameError}</p>}


      <input type="text"
      value={email}
      placeholder='Email'
      onChange={(e)=>{const value = e.target.value;
        setEmail(value);
        if(!validateEmail(value)){
          setEmailError("Please enter proper email")
        }
        else{setEmailError("");}
      }} />
      {emailError && <p style={{ color: 'red' }}>{emailError}</p>}
      <input type="password"
      value={password}
      placeholder='Password'
      onChange={(e)=>{
        const value = e.target.value;
        setPassword(value);
        if(!validatepassword(value)){
          setPasswordError("Enter atleast 6 feet long password");
        }
        else{setPasswordError("");}
      }} />
      {passwordError && <p style={{color:'red'}}>{passwordError}</p>}

    </>
  )
}

export default App
