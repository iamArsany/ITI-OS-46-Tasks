const removeDuplicatesSet = function (arrInput) {
  return new Set(arrInput);
};

const removeDuplicates = function (arrInput) {
  return arrInput.filter((num, idx, arr) => {
    return arr.indexOf(num) == idx;
  });
};

const reverseWords = function (arrInput) {
  let reversedArr = arrInput.map((elem) => {
    return elem.split("").reverse().join("");
  });
  return reversedArr;
};

const evenDuplicated = function (arr) {
  return arr.filter((elem) => elem % 2 == 0).map((elem) => elem * 2);
};

const secondLargest = function (arr) {
  let max = Math.max(...arr);
  return Math.max(...arr.filter((num) => max != num));
};

const EvenOddIndex = function (arr) {
  // let even = arr.filter((num, idx) => idx % 2 == 0);
  let even = [],
    odd = [];

  arr.map((num, idx) => {
    idx % 2 == 0 ? even.push(num) : odd.push(num);
  });
  // let odd = arr.filter((num, idx) => idx % 2 != 0);
  return [even, odd];
};

const counter = function (arr) {
  const res = arr.reduce((prev, curr) => {
    if (curr > 50) prev++;
    return prev;
  }, 0);
  return res;
};

const longestWord = function (arr) {
  return arr.reduce((prev, curr) => {
    if (curr.length > prev.length) {
      return curr;
    }
    return prev;
  }, arr[0]);
};

const generateArr = function (len, min, max) {
  arr = [];
  for (let index = 0; index < len; index++) {
    arr.push(Math.floor(Math.random() * (max - min) + min));
  }
  return arr;
};

const roundArr = function (arr) {
  return arr.map((num) => Math.round(num));
};

const countDays = function (arr) {
  return arr.map((date) => {
    return Math.round(
      new Date(Date.now() - new Date(date)) / (1000 * 60 * 60 * 24),
    );
  });
};

const sortDates = function (arr) {
  return arr.sort((a, b) => {
    return Date.parse(a) - Date.parse(b);
  });
};

console.log(EvenOddIndex([0, 1, 2, 3, 4, 5, 6]));
console.log(removeDuplicatesSet([1, 2, 2, 3]));
console.log(removeDuplicates([1, 1, 1, 1, 1, 2, 2, 3]));
console.log(reverseWords(["abcd", "efg"]));
console.log(evenDuplicated([1, 2, 3, 4, 5]));
console.log(counter([1, 2, 3, 34, 55, 303]));
console.log(longestWord(["bananaaaaa", "moooo", "appleee"]));
console.log(generateArr(5, 10, 100));
console.log(roundArr([1.3, 2.6, 12.1235]));
console.log(secondLargest([1, 2, 3, 4, 5]));
console.log(countDays(["2025-11-18", "2024-01-01", "2024-03-15"]));
console.log(sortDates(["2025-11-18", "2024-01-01", "2024-03-15"]));
