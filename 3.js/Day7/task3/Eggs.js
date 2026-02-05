class Eggs {
  constructor() {
    this.eggsList = [];
    this.eggImg = document.createElement("img");
    this.brokenEggimg = document.createElement("img");
    this.eggImg.src = "./assets/egg.png";
    this.brokenEggimg.src = "./assets/broken.png";
    this.eggImg.style.width = "50px";
    this.eggImg.style.height = "50px";
    this.brokenEggimg.style.width = "50px";
    this.brokenEggimg.style.height = "50px";
    this.drawEggs();
  }

  drawEggs() {
    setInterval(() => {
      let img = this.eggImg.cloneNode();
      img.style.position = "absolute";
      img.style.left = Math.random() * window.innerWidth - 60 + "px";
      document.querySelector("body").append(img);
      this.eggsList.push(img);
      this.startFalling(img);
    }, 1000);
  }

  startFalling(egg) {
    let topIdx = 1;
    setInterval(() => {
      topIdx += 10;
      egg.style.top = topIdx + "px";
      console.log("egg Top ,index: ", topIdx, window.innerHeight);
      if (topIdx > window.innerHeight - 50) {
        topIdx -= 10;
        egg.src = "./assets/broken.png";
        egg.style.top = topIdx + "px";
        this.removeEgg(egg);
      }
    }, 40);
  }

  removeEgg(egg) {
    setTimeout(() => {
      const index = this.eggsList.indexOf(egg);
      if (index !== -1) this.eggsList.splice(index, 1);
      egg.remove();
    }, 1000);
  }
}
