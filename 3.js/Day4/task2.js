const compineNamesAges = function () {
  names = ["Sara", "Ali", "Mona"];
  ages = [20, 22, 19];

  let arrObj = [];
  for (let i = 0; i < names.length; i++) {
    arrObj.push({ name: names[i], age: ages[i] });
  }

  return arrObj;
};

const countFreq = function () {
  let chars = ["a", "b", "a", "b", "b", "c"];
  let freq = {};

  for (let i = 0; i < chars.length; i++) {
    if (freq.hasOwnProperty(chars[i])) {
      freq[chars[i]] = freq[chars[i]] + 1;
    } else {
      freq[chars[i]] = 1;
    }
  }
  return freq;
};

const gradesGrouping = function () {
  let input = [10, 20, 30, 30, 40, 80, 90];
  let grades = {
    A: [],
    B: [],
    C: [],
    D: [],
    E: [],
    F: [],
  };

  for (let i = 0; i < input.length; i++) {
    switch (true) {
      case input[i] < 10:
        grades["F"].push(input[i]);
        break;
      case input[i] < 30:
        grades["E"].push(input[i]);
        break;
      case input[i] < 50:
        grades["D"].push(input[i]);
        break;
      case input[i] < 60:
        grades["C"].push(input[i]);
        break;
      case input[i] < 80:
        grades["B"].push(input[i]);
        break;
      case input[i] < 100:
        grades["A"].push(input[i]);
        break;

      default:
        break;
    }
  }
  return grades;
};

const sortGradesDesc = function (stdArrs) {
  stdArrs.sort((a, b) => {
    return b.grade - a.grade;
  });

  return stdArrs;
};

const highestGrade = function (stdArrs) {
  return sortGradesDesc(stdArrs)[0];
};

const convertToPascalCase = function (std) {
  std.firstName = TitleCase(std.firstName);
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
  return output;
};

const StudentsGreaterthan60 = function (studentsArr) {
  let stdarr = studentsArr.filter((std) => std.grade >= 60);
  return stdarr;
};

const convertArrtoStr = function (studentsArr) {
  let arr = studentsArr.map((obj) => obj.name + " " + obj.grade);
  return arr;
};
let stdArrrr = [
  { name: "Ali", grade: 70 },
  { name: "Sara", grade: 95 },
  { name: "Ahmed", grade: 30 },
  { name: "Mahmoud", grade: 39 },
];

const countStundetNameLetters = function (studentsArr) {
  studentsArr.reduce((prev, current) => {
    if (current.name.length >= 4) {
      console.log();
      prev++;
    }
    return prev;
  }, 0);
};

console.log("Compined: ", compineNamesAges());
console.log("frequency: ", JSON.stringify(countFreq()));
console.log("grades: ", JSON.stringify(gradesGrouping()));
console.log("Grades Order descending: ", sortGradesDesc(stdArrrr));
console.log("Highest Grade: ", highestGrade(stdArrrr));
console.log("Greater than 60: ", StudentsGreaterthan60(stdArrrr));
console.log("Convert arr of objects to string: ", convertArrtoStr(stdArrrr));
console.log("Count Letters: ", countStundetNameLetters(stdArrrr));
