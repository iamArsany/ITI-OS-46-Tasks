let students = [];

class Student {
  constructor(name, grade, department) {
    this.name = name;
    this.grade = Number(grade);
    this.department = department;
    console.log("here in the constructor");
  }
}
