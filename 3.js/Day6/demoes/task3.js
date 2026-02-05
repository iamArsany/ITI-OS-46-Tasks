setInterval(() => {
  let date = new Date();

  let day = date.getDay();
  let month = date.getMonth();
  let minutes = date.getMinutes();
  let seconds = date.getSeconds();
  let dateToDisplay = `${day}/${month} ${minutes}:${seconds}`;
  document.querySelector("title").innerText = dateToDisplay;
}, 1000);
