class Bird {
  constructor(container) {
    this.container = container;
    this.movingSpeed = 20;
    this.movingDown = 20;
    this.moveInterval = null;
    this.fallInterval = null;
    this.bird = document.createElement("img");
    this.#setDefaultValues();
    this.drawBird();
  }

  #setDefaultValues() {
    this.bird.src = "./images/bird.gif";
    this.bird.style.position = "absolute";
    this.bird.style.width = "100px";
    this.bird.style.height = "100px";
    this.bird.style.top = `${(Math.random() * (window.innerHeight + 1)) / 2}px`;
    this.bird.addEventListener("click", (e) => this.handleKilledBirds(e));
  }
  drawBird() {
    this.bird.style.top = `${(Math.random() * (window.innerHeight + 1)) / 2}px`;
    this.container.append(this.bird);
    this.moveBird(this.bird);
    console.log("here in the moving bird;", this.bird);
  }

  moveBird() {
    let speed = this.movingSpeed;
    this.moveInterval = setInterval(() => {
      speed += this.movingSpeed;
      this.bird.style.left = speed + "px";
      if (speed > window.innerWidth) {
        clearInterval(this.moveInterval);
        this.bird.remove();
      }
    }, 100);
  }
  fall() {
    let speed = parseInt(this.bird.style.top.split("px")[0]);
    this.fallInterval = setInterval(() => {
      speed += this.movingDown;
      this.bird.style.top = speed + "px";
      this.bird.style.transform = "rotate(90Deg)";
      console.log("Top: ", speed, this.bird.style.top, window.innerHeight);
      if (speed > window.innerHeight) {
        clearInterval(this.fallInterval);
        clearInterval(this.moveInterval);
        this.bird.remove();
      }
    }, 100);
  }

  handleKilledBirds(event) {
    clearInterval(this.moveInterval);
    this.moveInterval = 0;
    this.fall();
  }
}

class BirdsMaker {
  constructor(container) {
    this.container = container;
    this.spawn();
  }

  spawn() {
    setInterval(() => {
      let bird = new Bird(this.container);
    }, 1000);
  }
}

let container = document.querySelector("body");
let birds = new BirdsMaker(container);
// let bird = new Bird(container);
