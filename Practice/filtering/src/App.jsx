import { useState } from 'react'
import './App.css'



function App() {
  function toggle(id) {
  setTodo(todo.map(item => {
    if (item.id === id) {
      return {...item, completed: !item.completed};
    } else {
      return item;
    }
  }));
}
function deleteTodo(id) {
 setTodo(todo.filter(item => item.id !== id));
  

}

  function Addtodo(){
  if(inputVal == "" || inputVal == " "){
    console.error("the input is empty");
    return;  
  }
  const newtodo = {
    id: Date.now(),
    text: inputVal,
    completed : false,

  };
  setTodo([...todo,newtodo]);
  setInputVal("");
}
function Display() {
  return (
    <ol>
      {filteredTodos.map(item => (
        <li  key={item.id}>{item.text}
        <input type="checkbox" checked={item.completed} onChange={()=>toggle(item.id)} 
        
        />
        <button onClick={()=>{deleteTodo(item.id)}}>Delete</button></li>
      ))}
    </ol>
  )
}
  const [todo, setTodo] = useState([]);
  const [inputVal, setInputVal] = useState("");
  const [search, setSearch] = useState("");
  const filteredTodos = todo.filter(item => {
  return item.text.toLowerCase().includes(search.toLowerCase());
});




  return (
    <>
    <h1>todo List</h1>
    <input type="text" placeholder='Search'  onChange={(e) => setSearch(e.target.value)} />
    <input type="text"
    value={inputVal}
    onChange={(e)=>setInputVal(e.target.value)}
    placeholder='Add a placeholder' />
    <button onClick={Addtodo}>Add</button>
    
      <Display />
    </>
  )
}

export default App
