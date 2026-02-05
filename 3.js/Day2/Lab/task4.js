//Level 4

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
  console.log(output);
  return output;
};

const masking = function (input) {
  let output = "";
  for (let i = 0; i < input.length; i++) {
    if (i < input.length - 5) {
      output += "*";
    } else {
      output += input[i];
    }
  }
  console.log(output);
  return output;
};

const longestWord = function (input) {
  let current = "";
  let longestWord = "";

  for (let char of input) {
    if (char != " ") {
      current = current + char;
    } else {
      if (current.length > longestWord.length) {
        longestWord = current;
      }

      current = "";
    }
  }

  if (current.length > longestWord.length) {
    longestWord = current;
  }

  console.log("longest:", longestWord);
  return longestWord;
};

const removeRepeat = function (input) {
  let clean = "";

  for (let cIdx1 in input) {
    let alreadyAdded = false;

    for (let cIdx2 in clean) {
      if (input[cIdx1] == clean[cIdx2]) {
        alreadyAdded = true;
        break;
      }
    }

    if (!alreadyAdded && input[cIdx1] != " ") {
      clean = clean + input[cIdx1];
    } else if (input[cIdx1] == " ") {
      clean = clean + " ";
    }
  }

  console.log(clean);
  return clean;
};

masking("012353453463412315123");
TitleCase("hello world and brothers");
longestWord("ahmed mah fjfjfjjfj zx");
removeRepeat("ahmed mah fjfjfjjfj zx");
