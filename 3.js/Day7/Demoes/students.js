let addBtn = document.querySelector("input[type=button]");
let filterOptions = document.querySelectorAll("select")[1];
let sortOptions = document.querySelectorAll("select")[0];

addBtn.addEventListener("click", function () {
  let stdName = document.querySelector("input[name=studentName");
  let stdGrade = document.querySelector("input[name=studentGrade");
  let stdChecked = document.querySelector("input[type=radio]:checked");

  let std = new Student(stdName.value, stdGrade.value, stdChecked.value);
  students.push(std);
  createStudentRow(std);
});

const filterData = function (status) {
  let newData;
  studentTable.innerHTML = "";
  console.log("filter data value: ", status);
  if (status == "success") {
    console.log(students);
    newData = students.filter((std) => parseInt(std.grade) >= 60);
  } else if (status == "fail") {
    newData = students.filter((std) => parseInt(std.grade) < 60);
  } else {
    drawTable(students);
    return;
  }
  console.log(newData);
  drawTable(newData);
};

const drawTable = function (stdArr) {
  stdArr.forEach((element) => {
    createStudentRow(element);
  });
};

const sortData = function (value) {
  console.log("sort data value: ", value);
  let newData;
  studentTable.innerHTML = "";
  if (value == "name") {
    newData = students.sort((a, b) => a.name.localeCompare(b));
  } else {
    newData = students.sort((a, b) => a.grade - b.grade);
  }

  console.log(newData);
  drawTable(newData);
};
filterOptions.addEventListener("change", function () {
  filterData(this.value);
});

sortOptions.addEventListener("change", function () {
  sortData(this.value);
});
