console.log("Images: ");
console.log(document.images);
console.log(document.getElementsByTagName("img"));

//loop on the select options
let selectChildren = document.getElementsByTagName("select").City.children;
for (let i = 0; i < selectChildren.length; i++) {
  console.log(selectChildren[i].innerText);
}

//find 2nd table rows

let tableRows = document.getElementsByTagName("table")[1].rows;
for (let i = 0; i < tableRows.length; i++) {
  console.log(tableRows[i].innerHTML);
}

//find elements with 2 classes ( fontblue , bGrey)
document.getElementsByClassName("fontBlue bGrey");
