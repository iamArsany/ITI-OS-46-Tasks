let parentDiv = document.querySelector("#parentDiv");

let redTile = document.querySelector(".tile.red");
let greenTile = document.querySelector(".tile.green");
let blueTile = document.querySelector(".tile.blue");

const colorHandler = function (event) {
  let color = this.classList[1];
  let newDiv = addTile(color);
  parentDiv.append(newDiv);
  this.removeEventListener("click", colorHandler);
  newDiv.addEventListener("click", colorHandler);
};

const addTile = function (color) {
  let newDiv = document.createElement("div");
  newDiv.style.display = "inline-block";
  newDiv.classList = `tile ${color}`;
  return newDiv;
};

redTile.addEventListener("click", colorHandler);
greenTile.addEventListener("click", colorHandler);
blueTile.addEventListener("click", colorHandler);
