/**
 * 1- function Declaration
 * 2- Function Expression (best Practice)
 * 3- Arrow function ES6 (suger expression)
 * 4- IFFEE Function
 * 5- Higher Order Fuction
 */


//function delcartion
// //with no input and no output
// function getStudentDetails(){
//         console.log("Helloo OS ");
// }

// console.log(typeof getStudentDetails);

// //calling 
// getStudentDetails();


// //with no input and return
// function getStudentDetails(){
//       return  "Helloo OS ";
// }
// //calling
// console.log(getStudentDetails());

let number=5;

//with  input and return
function getStudentDetails(id){
    var studentName="eman"; //local
    age=20;
    number=50;
    console.log(studentName);
      return  "student id "+id;
}
//calling
console.log(getStudentDetails());
console.log(getStudentDetails(3));
console.log(getStudentDetails(number)); 

//Q 1: id scoping
console.log("id ",id);