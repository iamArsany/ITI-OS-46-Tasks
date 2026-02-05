const createBook = function (title, author, year, price) {
  isStringandValid(title);
  isStringandValid(author);
  isNumberAndValid(year);
  isNumberAndValid(price);

  let book = {
    title,
    author,
    year,
    price,
    bookDetails() {
      return this;
    },
    isClassic() {
      return 2025 - this.year >= 20 ? true : false;
    },
    applyDiscount(val) {
      isNumberAndValid(val);
      this.price = this.price * ((100 - val) / 100);
    },
  };

  return book;
};

const isStringandValid = function (value) {
  if (value == undefined || value == "") {
    throw new Error("Please provide all the necessary fields");
  }

  if (typeof value != typeof "") {
    throw new Error("accept only the type string");
  }
};

const isNumberAndValid = function (value) {
  if (value == undefined || value == null || value == 0) {
    throw new Error("Please provide all the necessary fields");
  }

  if (typeof value != typeof 1) {
    throw new Error("accept only the type Number");
  }
};

let book1 = createBook("first", "auth1", 2002, 200);
let book2 = createBook("sec", "auth2", 2020, 2000);
let book3 = createBook("third", "auth3", 2000, 100);
let book4 = createBook("fourth", "auth4", 2003, 500);
