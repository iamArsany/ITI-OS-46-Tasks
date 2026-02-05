// Level 3

const extractDomain = function () {
  let email = "user@example.com";
  let domain = email.substring(email.indexOf("@") + 1);
  console.log(domain);
};

const initialGenerator = function (input) {
  idx = 1;
  let output = "";
  output += input[0];
  while (true) {
    let ch = input.indexOf(" ", idx);
    if (ch != -1) {
      output += "." + input[ch + 1];
      idx = ch + 1;
    } else {
      break;
    }
  }
  console.log(output);
  return output;
};

const reverseString = function (input) {
  let output = "";

  for (let i = input.length - 1; i >= 0; i--) {
    output += input[i];
  }
  console.log(output);
  return output;
};

const palindromeCheck = function (input) {
  let rev = reverseString(input);
  return rev == input;
};

const countVowels = function (input) {
  let counter = 0;
  for (let i = 0; i < input.length; i++) {
    switch (input[i]) {
      case "a":
      case "e":
      case "i":
      case "o":
      case "u":
        counter++;
        break;
    }
  }
  console.log(counter);
  return counter;
};

// initialGenerator("john smith Andrew Garfiled");
// reverseString("just a test");
// reverseString("testing");
countVowels("ahmedi");
