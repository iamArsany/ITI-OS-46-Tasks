const getStudent = function () {
  let firstName = prompt("FirstName:");
  let lastName = prompt("LastName:");
  let age = parseInt(prompt("age:"));
  let email = prompt("email:");
  while (!isvalidEmail(email)) {
    email = prompt("Enter correct Email: ");
  }
  let dept = prompt("Department:");

  let student = {
    firstName,
    lastName,
    age,
    email,
    dept,
  };

  return student;
};

//helper function for email validation
const isvalidEmail = function (email) {
  const emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
  return emailRegex.test(email);
};

const getArrStudents = function () {
  let input = parseInt(prompt("Enter Number of students"));
  let studentsArr = [];
  for (let i = 0; i < input; i++) {
    studentsArr.push(getStudent());
  }

  return studentsArr;
};

const oldestStudentFullName = function (studentsArr) {
  studentsArr.sort((a, b) => {
    return b.age - a.age;
  });

  return studentsArr[0].firstName + " " + studentsArr[0].lastName;
};

const convertToPascalCase = function (std) {
  std.firstName = TitleCase(std.firstName);
  std.lastName = TitleCase(std.lastName);
  return std;
};
//helper function
const TitleCase = function (input) {
  let output = "";
  output += input[0].toUpperCase();

  for (let i = 1; i < input.length; i++) {
    if (input[i] == " ") {
      output += " ";
      output += input[i + 1].toUpperCase();
      i++;
    } else {
      output += input[i];
    }
  }
  console.log(output);
  return output;
};

const StudentsGreaterthan20 = function (studentsArr) {
  let stdarr = studentsArr.filter((std) => std.age > 20);
  return stdarr;
};

const getAverage = function (studentsArr) {
  let sum = studentsArr.reduce((prev, current) => {
    return prev + current.age;
  }, 0);
  sum = sum / studentsArr.length;
  return sum;
};

const sortByNames = function (studentsArr) {
  studentsArr.sort((a, b) => {
    const firstCompare = a.firstName.localeCompare(b.firstName);
    if (firstCompare !== 0) return firstCompare;
    return b.lastName.localeCompare(a.lastName);
  });

  return studentsArr;
};

const newArr = function (studentsArr) {
  let arr = [];
  for (student of studentsArr) {
    let fullName = student.firstName + " " + student.lastName;
    arr.push({ fullName, age: student.age });
  }
  return arr;
};

const overrideStudent = function (studentsArr) {
  let firstName = studentsArr.firstName;
  let lastName = studentsArr.lastName;
  let age = studentsArr.age;
  let email = studentsArr.email;
  let dept = studentsArr.dept;

  let student = {
    firstName,
    lastName,
    fullName: this.student.firstName + " " + this.student.lastName,
    age,
    email,
    dept,
    toString() {
      return this.fullName.toString();
    },
  };
  return student;
};

let studentsArrr = [
  {
    firstName: "bs",
    lastName: "cd",
    age: 20,
    email: "asdf@gmail.com",
    dept: "cs",
  },
  {
    firstName: "ah",
    lastName: "ba",
    age: 10,
    email: "asdf@gmail.com",
    dept: "cs",
  },
  {
    firstName: "Cv",
    lastName: "Ls",
    age: 30,
    email: "fda@gmail.com",
    dept: "vc",
  },
];

// let studentsArrr = getArrStudents();
let oldestStudent = oldestStudentFullName(studentsArrr);
console.log(oldestStudent);
let pascalCase = convertToPascalCase(studentsArrr[0]);
console.log(pascalCase);
let studentsfiltering = StudentsGreaterthan20(studentsArrr);
console.log("Filter by age: ", studentsfiltering);
let averageStudents = getAverage(studentsArrr);
console.log("Average: ", averageStudents);
let sortedArr = sortByNames(studentsArrr);
console.log("SortedArr: ", sortedArr);
let newArray = newArr(studentsArrr);
console.log("New Array: ", newArray);
let overridedStudent = overrideStudent(studentsArrr[0]);
console.log(overridedStudent);
