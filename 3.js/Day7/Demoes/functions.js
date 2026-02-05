console.log("here in the functions file");
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

  //handel delete
  deleteBtnElem.onclick = function () {
    this.parentElement.parentElement.remove();
  };
  return trElm;
};

let studentTable = document.querySelector("table[id=studentsData]");
let st1 = new Student("ahmed", 20, "os");
let st2 = new Student("Eman", 30, "os");
createStudentRow(st1);
students.push(st1);
createStudentRow(st2);
students.push(st2);
