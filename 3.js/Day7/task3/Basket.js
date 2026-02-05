class Basket {
  constructor(eggsInstance) {
    this.eggs = eggsInstance;
    this.basket = document.createElement("img");
    this.setDefaultValues();
    this.setKeybindings();
    this.setScoreCounter();
    this.handleCollision();
    this.moveAmount = 60;
    this.score = 0;
  }

  setKeybindings() {
    document.addEventListener("keydown", (e) => {
      let currentLeft = parseInt(this.basket.style.left);

      if (e.key === "ArrowLeft" || e.key.toLowerCase() === "a") {
        currentLeft -= this.moveAmount;
      } else if (e.key === "ArrowRight" || e.key.toLowerCase() === "d") {
        currentLeft += this.moveAmount;
      }
      currentLeft = Math.max(0, Math.min(window.innerWidth - 100, currentLeft));
      this.basket.style.left = currentLeft + "px";
    });
  }

  setDefaultValues() {
    this.basket.src = "./assets/basket.png";
    this.basket.position = "absolute";
    this.basket.style.width = "100px";
    this.basket.style.height = "100px";
    this.basket.style.position = "absolute";
    this.basket.style.top = `${window.innerHeight - 100}px`;
    this.basket.style.left = `${window.innerWidth / 2 - 100}px`;
    document.querySelector("body").append(this.basket);

    this.scoreBox = document.createElement("div");
    this.scoreBox.style.position = "fixed";
    this.scoreBox.style.top = "20px";
    this.scoreBox.style.left = "20px";
    this.scoreBox.style.fontSize = "30px";
    this.scoreBox.style.fontWeight = "bold";
    this.scoreBox.innerText = "Score: 0";
    document.body.append(this.scoreBox);
  }
  setScoreCounter() {
    this.updateScore = () => {
      this.score++;
      this.scoreBox.innerText = `Score: ${this.score}`;
    };
  }

  handleCollision() {
    setInterval(() => {
      this.eggs.eggsList.forEach((egg, index) => {
        const eggRect = egg.getBoundingClientRect();
        const basketRect = this.basket.getBoundingClientRect();

        const isTouching =
          eggRect.left < basketRect.right &&
          eggRect.right > basketRect.left &&
          eggRect.bottom > basketRect.top &&
          eggRect.top < basketRect.bottom;

        if (isTouching && egg.src.includes("egg.png")) {
          this.updateScore();
          egg.remove();
          setTimeout(() => {
            this.eggs.eggsList.splice(index, 1);
          }, 300);
        }
      });
    }, 30);
  }
}
