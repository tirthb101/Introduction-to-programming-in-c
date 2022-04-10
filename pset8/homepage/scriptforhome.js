const news = [
 {
     headline: "Headline 1",
     text: "This is in detail new about the incident which had headline of headline 1.this in incident took place on  this day and at this time.",
     date: "28/2/2020",
     file: "article1.html",
 },
 {
     headline: "Headline 2",
     text: "This is in detail new about the incident which had headline of headline 1.this in incident took place on  this day and at this time.",
     date: "22/5/2020",
     file: "article2.html",
 }

]

document.addEventListener("DOMContentLoaded", () => {
   news.forEach( list =>
   document.querySelector(".mid").innerHTML += `<li><h5><a href = "${list.file}">${list.headline}</a></h5> &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp ${list.text} <h6>${list.date}</h6></li>`

   )}
)