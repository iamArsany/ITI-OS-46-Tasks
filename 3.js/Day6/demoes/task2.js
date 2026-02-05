// change the first anchor point
document.getElementsByTagName("table")[1].getElementsByTagName("a")[0].href =
  "Training.com";
document.getElementsByTagName("table")[1].getElementsByTagName("a")[0].text =
  "training";

// change all the images
let images = document.getElementsByTagName("img");

for (let i = 0; i < images.length; i++) {
  images[i].style.border = "solid pink 2px";
}

// change input values
// document.getElementsByTagName('form').regForm.querySelectorAll('input[type=checkbox]')[0].value
let inputSelectors = document
  .getElementsByTagName("form")
  .regForm.querySelectorAll("input[type=checkbox]");

inputSelectors.forEach((element) => {
  element.value = "123";
});

let inputSelectorsChecked = document
  .getElementsByTagName("form")
  .regForm.querySelectorAll('input[type=checkbox][checked=""]')[0]
  .removeAttribute("checked");

//change id element to be pink color
document.getElementById("example").style.color = "pink";
