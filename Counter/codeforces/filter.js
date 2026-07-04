Array.Filter.prototype =() => {
    for(i =0; i < this.length; i++)
    {
        output = [];
        if(this[i] === 0)
        {
            output.push(this[i]);
        }
        
    }
    return output;
}