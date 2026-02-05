let filterOptions = document.querySelectorAll("select")[1];
let sortOptions = document.querySelectorAll("select")[0];

const createStudentRow = function (student) {
  let trElm = document.createElement("tr");
  studentTable.append(trElm);

  for (let property in student) {
    let tdElem = document.createElement("td");
    tdElem.innerText = student[property];
    trElm.append(tdElem);
  }
  // adding delete button
  let tdElem = document.createElement("td");
  trElm.append(tdElem);
  let deleteBtnElem = document.createElement("button");
  deleteBtnElem.innerText = "Delete";
  tdElem.append(deleteBtnElem);

  if (trElm) {
    let dept = trElm.children[2].innerText.toUpperCase();
    if (dept === "OS") {
      trElm.style.backgroundColor = "indianred";
      trElm.style.color = "white";
    } else if (dept === "EL") {
      trElm.style.backgroundColor = "lightblue";
    } else {
      trElm.style.backgroundColor = "lightgreen";
    }
  }
  //handle delete
  deleteBtnElem.onclick = function () {
    let row = this.parentElement.parentElement;
    let name = row.children[0].innerText;
    row.remove();
    students = students.filter(
      (std) => std.name.toLowerCase() !== name.toLowerCase(),
    );
  };

  return trElm;
};

const filterData = function (status) {
  let newData;
  studentTable.innerHTML = "";
  if (status == "success") {
    newData = students.filter((std) => parseInt(std.grade) >= 60);
  } else if (status == "fail") {
    newData = students.filter((std) => parseInt(std.grade) < 60);
  } else {
    drawTable(students);
    return;
  }
  drawTable(newData);
};

const drawTable = function (stdArr) {
  stdArr.forEach((element) => {
    createStudentRow(element);
  });
};

const sortData = function (value) {
  let newData;
  studentTable.innerHTML = "";
  if (value == "name") {
    newData = students.sort((a, b) => a.name.localeCompare(b.name));
  } else {
    newData = students.sort((a, b) => a.grade - b.grade);
  }

  drawTable(newData);
};
filterOptions.addEventListener("change", function () {
  filterData(this.value);
});

const isValidName = function (name) {
  if (name.length == 0) return false;
  return true;
};

const isNameDuplicated = function (name) {
  if (students.length) {
    for (let std of students) {
      if (std.name.toLowerCase() == name.toLowerCase()) {
        return true;
      }
    }
  }
  return false;
};
const isValidGrade = function (grade) {
  console.log("numb inside validation before:", grade);
  if (grade == "") return false;
  let num = Number(grade);
  if (isNaN(num)) return false;
  return num >= 0 && num <= 100;
};
sortOptions.addEventListener("change", function () {
  sortData(this.value);
});

const pascalCase = function (input) {
  console.log("here in the pascalCase");
  let output = "";
  output += input[0].toUpperCase();
  for (let i = 1; i < input.length; i++) {
    output += input[i];
  }

  return output;
};

let studentTable = document.querySelector("table[id=studentsData]");
let st1 = new Student("ahmed", 20, "OS");
let st2 = new Student("Eman", 30, "SD");
createStudentRow(st1);
createStudentRow(st2);

students.push(st1);
students.push(st2);
