let addBtn = document.querySelector("input[type=button]");
let stdName = document.querySelector("input[name=studentName]");
let stdGrade = document.querySelector("input[name=studentGrade]");
let nameErrMsg = document.querySelector("#nameError");
let dataErrMsg = document.querySelector("#DataError");
let gradeErrMsg = document.querySelector("#gradeError");

addBtn.addEventListener("click", function () {
  console.log("data: ", students);
  let stdChecked = document.querySelector("input[type=radio]:checked");

  dataErrMsg.style.display = "none";

  if (!isValidName(stdName.value)) {
    nameErrMsg.style.display = "inline";
    nameErrMsg.textContent = "Name is required!";
    return;
  } else {
    nameErrMsg.style.display = "none";
  }

  if (isNameDuplicated(stdName.value)) {
    dataErrMsg.style.display = "inline";
    dataErrMsg.textContent = "Name is Duplicated!";
    return;
  } else {
    dataErrMsg.style.display = "none";
  }

  if (!isValidGrade(stdGrade.value)) {
    gradeErrMsg.style.display = "inline";
    return;
  } else {
    gradeErrMsg.style.display = "none";
  }
  let stdGradeNum = Number(stdGrade.value);
  let stdNamePascaled = pascalCase(stdName.value);
  let std = new Student(stdNamePascaled, stdGradeNum, stdChecked.value);
  students.push(std);
  createStudentRow(std);
});

stdName.addEventListener("blur", function (event) {
  if (!isValidName(event.target.value)) {
    nameErrMsg.style.display = "inline";
  } else {
    nameErrMsg.style.display = "none";
  }
});

stdGrade.addEventListener("blur", function (event) {
  console.log("event grade:", event.target.value);
  console.log("event grade std:", stdGrade.value);
  if (!isValidGrade(event.target.value)) {
    gradeErrMsg.style.display = "inline";
  } else {
    gradeErrMsg.style.display = "none";
  }
});
