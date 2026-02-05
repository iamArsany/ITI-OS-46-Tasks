let input = prompt("Enter a Word");

console.log("Length: ", input.length);
console.log("UpperCase: ", input.toUpperCase());
console.log("LowerCase: ", input.toLowerCase());

console.log("First: ", input.charAt(0));
console.log("middle: ", input.charAt(parseInt(input.length / 2)));
console.log("last: ", input.charAt(input.length - 1));

// let firstName = prompt("Enter your First Name:");
// let secondName = prompt("Enter your Second Name:");
// console.log(`Hello ${firstName} ${secondName}`);
let output = "";
output = input.substring(0, input.length - 5);
console.log("Output after Cutting: ", output);

//LEVEL 2

let sent = "Hello this is just a test";
let wordToFind = "just";

sent.includes(wordToFind);
sent.indexOf(wordToFind);

sent.replace(wordToFind, "not");

const countingChars = function (char) {
  let counter = 0;
  for (let i = 0; i < sent.length; i++) {
    if (sent[i] == char) {
      counter++;
    }
  }
  return counter;
};

sent.startsWith("Hello");
sent.endsWith("test");

const newSent = sent.replaceAll(" ", "");
console.log(sent);
console.log(newSent);
