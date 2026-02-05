console.log("hereeee");
let img = document.querySelector("img");

const StartSliding = function (imgObj) {
  console.log("hereeee");
  let i = 0;
  let id = setInterval(() => {
    console.log("hereeee");
    if (i < 8) document.images[1].src = `./demoes/images/${++i}.jpg`;
    else i = 0;
  }, 1000);

  return id;
};

const stopSliding = function (imgID) {
  clearInterval(imgID);
};

StartSliding(img);
