let startBtn = document.getElementById("startBtn");

startBtn.addEventListener("click", function (event) {
  this.parentElement.querySelector("#startBtn").remove();
  startGame();
});
