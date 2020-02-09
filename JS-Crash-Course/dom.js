//DOM - Document Object Manipulation
//Parent object of browser
console.log(window);
//Single element selectors
console.log(document.getElementById('my-form'));
const form = document.getElementById('my-form');
console.log(form);
//Query Selectors
//Grab the container class
const container = document.querySelector('.container');
console.log(container);
//Grab first instance of any tag
const headerTag = document.querySelector('h1');
console.log(headerTag);

//Multiple element selectors
//Can perform array ops on it
//querySelectorAll works on classes, ids and tags
console.log(document.querySelectorAll('.item'));
const items = document.querySelectorAll('.item');
for (let item of items) {
    console.log(item);
}

//Manipulating the DOM
