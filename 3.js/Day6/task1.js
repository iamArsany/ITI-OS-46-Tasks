const startBirdMoving = function () {
  let movingObj = document.querySelector("img").cloneNode();
  let left = Math.floor(Math.random() * 100);
  let top = Math.round((Math.random() * 100) % (window.innerHeight / 2));
  let speed = Math.floor(Math.random() * 50) + 50;
  let objCords = Math.floor(Math.random() * 50) + 50;
  let pos = 1;
  let isReversed = false;
  movingObj = setDefaultStyleOptions(movingObj, left, top, objCords);
  document.body.append(movingObj);

  let id = setInterval(() => {
    left += 20;
    if (left < window.innerWidth - objCords) {
      if (isReversed && movingObj.offsetLeft <= 20) {
        isReversed = false;
        pos *= -1;
        movingObj.style.transform = `scaleX(${pos})`;
      }
      movingObj.style.left = Math.abs(left) + "px";
      movingObj.style.top = Math.abs(top) + "px";
    } else {
      isReversed = true;
      left *= -1;
      pos *= -1;
      movingObj.style.transform = `scaleX(${pos})`;
    }
  }, speed);

  return id;
};

const setDefaultStyleOptions = function (movingObj, left, top, cords) {
  movingObj.style.position = "absolute";
  movingObj.style.width = `${cords}px`;
  movingObj.style.height = `${cords}px`;
  movingObj.style.left = Math.abs(left) + "px";
  movingObj.style.top = Math.abs(top) + "px";

  return movingObj;
};

startBirdMoving();
startBirdMoving();
startBirdMoving();
