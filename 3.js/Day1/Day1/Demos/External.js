/**
 * Hoisting
 * var userName;
 * var number_1;
 * var number_2;
 * var number_3;
 */


//Q1: what if we have a problem (syntax error)
        // console.lo("Hi ..."); //Error
        // console.log("Hello From External Script");

    /**********  ES5 Variables (loosely type langauge) */
    // console.log("befdore dfinition username= ",userName); //Hoisting
    // console.log("befdore dfinition number_1= ",number_1); //Hoisting
    var  userName;
    var number_1=2;
    var number_2=2.2, number_3=3e3;
    // console.log("number_4= ",number_4);//Error 
    
    number_4=1000;

    // console.log("username= ",userName);
    //Q2 : what is userName scope???

    //Q3: ask JS about primitive datatypes names
    // console.log("type of number_1" ,typeof number_1);




    /*********************************
     * var definition Problems
     * 1- hoisting
     * 2- redeclaration var count=30;
     * 3- block scoping  var always global except inside functions 
     * (ES5 functional scoping langauge)
     */
    // solution : ES6  define variables with let and const

var count=30;

// define with ES6
// console.log("before number_7= ",number_7);//Error
let number_7=70;
const number_9=100;
    // console.log("number_7= ",number_7);//??

if(true)
{
    // console.log("number_7= ",number_7);//??
    // var userName="Eman";
    let number_7=90;
    // console.log("number_7= ",number_7);
}

if(true)
{
    // console.log("number_8= ",number_8);
    let number_8=80;
}
for(var i=0;i<2;i++)
{
    console.log(i);
}

    // console.log("number_7= ",number_7);

//change value
// number_7=77;
// console.log(typeof number_7);
// number_7="eman";
// console.log(typeof number_7);

/****  datatype string */
let instructorName="eman";
let studentName='Ahmed';
// deakl with string as array of characters
console.log(instructorName[1]);
console.log(typeof instructorName[1]);

instructorName[1]="Mdkfjlkdsjflksdjflksjdflkdsjlfkjdkl"; // change value by index (string are immutable)
// console.log(instructorName);
instructorName+=" ahmed";
// console.log(instructorName);
instructorName="mona"; // will be cahnged in memory (eman will be destroyed)

let instructorDetials='eman\'s courses are ["JS","NodeJS"]';
let tableContent="<table><tr><td>"+instructorName+"</td><td>"+studentName+"</td></tr></table>"

//ES6  backtick `  multiline and Template literal ${}

tableContent=`<table>
                    <tr>
                        <td> ${instructorName}}</td>
                        <td>${studentName} </td>
                    </tr>
                </table>`;
let flag=true;

//Q4: what if   
//flag + 6;
//flag+ instructorName


// null
let student=null;
console.log(typeof student);

