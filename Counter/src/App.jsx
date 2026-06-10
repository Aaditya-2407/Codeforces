import React from 'react';
import {useState} from 'react';
import Counter from './components/Counter';
import ToDo from './components/ToDo';
import Main from './components/Main';

function App() {
 

  return (
    <div>
     <Counter />
     <ToDo />
     <Main />

    </div>
  )
}

export default App
