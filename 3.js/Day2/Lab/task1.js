// Task1.1
const getStudentGrades1 = function () {
  for (let i = 0; i < 3; i++) {
    let student = prompt(`Enter Student ${i + 1}:`);
    console.log(student);
  }
};

// Summation
const getStudentGrades2 = function () {
  let sum = 0;
  for (let i = 0; i < 3; i++) {
    let studentGrade = prompt(`Enter Student ${i + 1}:`);
    sum += parseInt(studentGrade);
  }
  console.log(sum);
};

// Dynamic input and summation
const getStudentGrades3 = function () {
  let sum = 0;
  let totalStudents = parseInt(prompt(`Enter Number of Students`));
  for (let i = 0; i < totalStudents; i++) {
    let studentGrade = prompt(`Enter Student ${i + 1}:`);
    sum += parseInt(studentGrade);
  }
  console.log(sum);
};

// Validation
const getStudentGrades4 = function () {
  let sum = 0;
  let totalStudents = parseInt(prompt(`Enter Number of Students`));
  for (let i = 0; i < totalStudents; i++) {
    let studentGrade = parseInt(prompt(`Enter Student ${i + 1}:`));
    if (studentGrade > 2 && studentGrade < 10) {
      sum += studentGrade;
    } else {
      alert(`Student Number ${i + 1} entered invalid value`);
      break;
    }
  }
  console.log(sum);
};

// number validation & summation
const getStudentGrades5 = function () {
  let sum = 0;
  let totalStudents = parseInt(prompt(`Enter Number of Students`));
  for (let i = 0; i < totalStudents; i++) {
    let studentGrade = Number(prompt(`Enter Student ${i + 1}:`));
    if (!isNaN(studentGrade)) {
      sum += studentGrade;
    } else {
      sum += 0;
    }
  }
  console.log(sum);
};

// prompt again !
const getStudentGrades6 = function () {
  let sum = 0;
  let totalStudents = parseInt(prompt(`Enter Number of Students`));
  for (let i = 0; i < totalStudents; i++) {
    let studentGrade = Number(prompt(`Enter Student ${i + 1}:`));
    if (!isNaN(studentGrade) && studentGrade > 0 && studentGrade < 100) {
      sum += studentGrade;
    } else {
      while (true) {
        alert("You entered the prompt with invalid Value!!");
        let studentGrade = Number(
          prompt(`please Enter Student ${i + 1} again:`),
        );
        if (isNaN(studentGrade)) {
          continue;
        } else {
          if (studentGrade > 0 && studentGrade < 100) {
            sum += studentGrade;
            break;
          } else {
            continue;
          }
        }
      }
    }
  }
  console.log(sum);
};
getStudentGrades6();
