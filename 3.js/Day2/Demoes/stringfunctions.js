const stringSwitchingCase=function(input){

    let output="";
    for(let i=0;i<input.length;i++)
    {
        if(input[i]==input[i].toLowerCase())
        {
            output+=input[i].toUpperCase();
        }
        else
            output+=input[i].toLowerCase();

    }

    return output;

}