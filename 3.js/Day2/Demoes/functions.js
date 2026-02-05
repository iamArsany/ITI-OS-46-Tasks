// var getInstructorData

// function getStudentDetails(id=0,name="")
// {
//     console.log(arguments);

//     return `Hello ${name} you id is ${id}`;
// }

/**
 * Functions Types
 * 1- Function Declaration
 * 2- Function Expression
 * 3- Arrow Function
 * 4- CallBack functions and Anonymouse Functions
 * 5- IFEE Functions
 */

//Function Declaration
getStudentDetails(1,"xxx");
function getStudentDetails(id=0,name="")
{
    console.log(arguments);

    return `Hello ${name} you id is ${id}`;
}

//Q : What if we send less parameters
// getStudentDetails();  // 

//Q : What if we insert too many paratmetrs
// getStudentDetails(2,"eman",3,4,5);  // 

//Q: what if we insert differnet dataType
// getStudentDetails("eman",33);

//Q : why JS accept many parameters
function sum()
{
    //array-like  arguments
    console.log(arguments);
    let result=0;
    for(let i=0;i<arguments.length;i++)
    {
        result+=arguments[i];
    }
    return result;
}

//Q :  Default Parameters  ES6

//Q: functions are variables 
// getStudentDetails="eman";


//Q : Fucntion hoisting

/*********** Fucntion Expression  + const */
// getInstructorData(2,"yyy");  undefined(2,"yyy")  is npt a function
// getInstructorData; //undefined
// var getInstructorData=function(id,name){
//     console.log(arguments);

//     return `Hello ${name} you id is ${id}`;
// }


/**********  Arrow Function  (ES6)   replace function with =>
 * must be decalred with function expression
 * Diff :  no arguments array-Like ,  doesn't contain this keyword
*/
// const setDBConnection= (i/p)   =>{o/p}
// const setDBConnection= (connectionString)  =>{return ` connectio setting ${connectionString}`};
// const setDBConnection= connectionString  =>` connectio setting ${connectionString}`;
// if we have function body
const setDBConnection= connectionString  =>{
    console.log(arguments);
   return ` connectio setting ${connectionString}`
};

// console.log(typeof setDBConnection);




