// (()=>{
//     let numebr=2;
//     let projectName="ITI";
//     const getData=()=>{}

//     return {number:number,getInfo:getData}
// })()



/**
 * Object Oriented in Javascript
 * Part 1 :  User Defined Objects (Anonymouse Objects)
 * Part 2 :  Classes 
 */

let numbers=[1,2,3];
let studentName=new String("xxx");

console.log(numbers+""); //toString()
console.log(studentName+"");//toString()

// let student={
//     id:30,
//     fullName: { firstName:"xxx", lastName:"yyy"},
//     jobTitle:"Freelnacer",
//     age:30,
//     "full address":"123456"
// };
// console.log(typeof student);
// console.log(student.constructor.name);
// console.log("our object as string ",   student+"");

// Why Anynouse object 

// Call properties
// student.age; //getting
// student.age=30;  //setting

//calling as index
// student["age"]; //getting
// student["age"]=20; //setting

//looping through object for in 
// for(let property in student)
{
    // console.log(student[property]);
}


// adding properties 
// student.courses=["x","y","z"]
// student["email"]="x@gmail.com"

//deleteing properties
// delete student.age;

console.log(this);
/***************  Object with functions  */
// let fullName={firstName:"zzz"};
let student={
    id:30,
    fullName: { firstName:"xxx", lastName:"yyy"},
    jobTitle:"Freelnacer",
    age:30,
    "full address":"123456",
    // study: ()=>{  // forbidden
    //     console.log(`Student ${this} is studying...`);
    // }
    //ES6 concise Method
     study (){ 
        console.log(`Student ${this.fullName.firstName} is studying...`);
    },
    toString(){
        return this.fullName.firstName+ " "+this.fullName.lastName;
    }
};


// calling
student.study();
student["study"]();

// adding method

student.sleeping=function(){
    console.log("sleeping...");
}
//delete
delete student.sleeping;

//*************  this keyword */

// console.log(this);//window object;
// var number_1=1;
// number_2=2; //forbidden  -->  this.number_2=2 --> adding property on window object
// let number_3=3;


// function getStudentData(){

// // var , let , const local variables
// //forbidden   
// age=30;
// console.log(this);//window


// }


/********************
 *  JSON   (Javscript Object notation)
 */

// JSON

// JSON.stringify(student);//'{"id":30,"fullName":{"firstName":"xxx","lastName":"yyy"},"jobTitle":"Freelnacer","age":30,"full address":"123456"}'
// JSON.parse('{"id":30,"fullName":{"firstName":"xxx","lastName":"yyy"},"jobTitle":"Freelnacer","age":30,"full address":"123456"}');


// Task :  create many students using createFunction , then apply array method

const createStudent=function(id, firstName, lastName,age)
{
    return {id,fullName:{firstName,lastName},age}

}

let students=[];


students.push(createStudent(2,"eman","ahmed",30));
students.push(createStudent(3,"mona","mohamed",20));
students.push(createStudent(1,"ahmed","ali",25));


// Task1.1   serach for eman as first Name 

students.filter(obj=>obj.fullName.firstName=="eman")

//Task1.2  ages> 20
students.filter(obj=>obj.age>20);

//Task1.3  sort by age
students.sort((a,b)=>a.age-b.age);





















