function checkEvenOdd(num) {
  if (typeof num === typeof 3) {
    if (num % 2 == 0) {
      console.log("Even");
    } else {
      console.log("Odd");
    }
  } else {
    console.log("Now Allowed!, provide a number");
  }
}

function print1to10() {
  for (let index = 1; index <= 10; index++) {
    console.log(`Number: ${index}`);
  }
}

function checkpos(num) {
  if (num > 0) {
    console.log("Pos");
  } else if (num < 0) {
    console.log("Neg");
  } else {
    console.log("Zero");
  }
}

function mulTable(num) {
  for (let i = 1; i <= 12; i++) {
    console.log(`${i} x ${num} = ${i * num}`);
  }
}

function numToDay(num) {
  if (num == 1) {
    console.log("Saturday");
  } else if (num == 2) {
    console.log("Sunday");
  } else if (num == 3) {
    console.log("Monday");
  } else if (num == 4) {
    console.log("Tuesday");
  } else if (num == 5) {
    console.log("Wedensday");
  } else if (num == 6) {
    console.log("Thursday");
  } else if (num == 7) {
    console.log("Friday");
  }
}

function checkWeekend(num) {
  if (num === 2 || num === 7) {
    console.log("Weekend");
  } else {
    console.log("you have to go to work :(");
  }
}
