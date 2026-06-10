import axios from "axios";
import { useState, useEffect } from "react";
import "../style.css";

function Main()
{
    const [item, setitems] = useState([]);
    useEffect(() => {
        axios
            .get("https://www.themealdb.com/api/json/v1/1/filter.php?c=Seafood")
            .then((res) => {
                setitems(res.data.meals);
            })
            .catch((err) => {
                console.log(err);
            })
            .catch((err) => {
                console.log(err);
            });
    }, []);

    const itemlist = item.map(({strMeal, strMealThumb, idMeal}) => {
        return (
            <section className="card">
                <img src={strMealThumb} alt={strMeal} />
                <section className="content">
                <p>{strMeal}</p>
                <p>#{idMeal}</p>
                </section>
                
            </section>
        )
    })
}
export default Main;