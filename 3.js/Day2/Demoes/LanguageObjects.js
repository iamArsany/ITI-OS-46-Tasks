/**
 *  DataTypes: Primitive and Objects
 *  1- LanguageObjects (String, Array, Date ,,,,,,,)
 *  2- DOM Objects
 *  3- UserDefined Objcts
 */
//String Class


//create Object
let userName=new String("noha ahmed ali");
let clientName=new String("noha ahmed ali");
let instrcutorName="eman ITI instructor";
console.log(typeof instrcutorName);
console.log(typeof userName);
//ASk about class Name
// console.log(userName.constructor.name);

//Why String exixts --> we have a primitve type

//What if we used Pron=mitve trype
//wrapping  primitive into object
/** 1- new String(instrcutorName);
 * 2- use the fucntuion --> toUpperCase()
 * 3- destroy
 *  */ 
// console.log(instrcutorName.toUpperCase());
// console.log(typeof instrcutorName);

// Q : Equality with objects
// console.log(userName==clientName);//false
// console.log(userName=="noha ahmed ali");//true (like false==0)
// console.log(userName==="noha ahmed ali");//false

// Methods
//indexOf

//Task
// input string and return it's wsitching case
//input: Ahmed  return aHMED

//console.log( stringSwitchingCase("Eman"));