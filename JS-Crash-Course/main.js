//Output to console
console.log('Hello, World!');
console.error('Throw error');

//Variable assignment
let age = 22;
const id = 1234; //constants can't change
console.log(age);
console.log(id);
age = 23;
//id = 4321;
console.log(age);

//Data Types
const name = 'John';
const age2 = 22;
const isCool = true;
const rate = 4.4;
const x = null;
const y = undefined;

console.log('Primitive Data Types!');
console.log('age: ' + age + ', age is a ' + typeof age2);
console.log('name: ' + name + ', name is a ' + typeof name);
console.log('isCool: ' + isCool + ', isCool is a ' + typeof isCool);
console.log('rate: ' + rate + ', rate is a ' + typeof rate);
console.log('x: ' + x + ', x is a ' + typeof x + '. But null is NOT an object');
console.log('y: ' + y + ', y is a ' + typeof y);

//Template literals, strings `` double ticks
console.log('Working witth strings!');
console.log(`My name is ${name} and I am ${age} years old`);
honestReview = `Power Rangers was a solid ${rate}/5.0 and was it cool: ${isCool}`;
console.log(honestReview);

//String properties and methods
//Methods:(), properties 
const str = 'Hello, World!';
console.log('String: ' + str);
console.log(`Length: ${str.length}`);
console.log(`To upper case: ${str.toUpperCase()}`);
//include: 0 exclude: 5
console.log(`Substring from i: 0 to j:7 -> ${str.substring(0,7)}`);
console.log(`Split string into array of characters: ${str.split('')}`);
console.log(str.split(''));
console.log('Split string into array using ,space seperator');
console.log(str.split(', '));

//Arrays
const numbers = new Array(1,2,3,4,5);
const fruit = new Array('Apple','Banana','Pear','Orange');
console.log(numbers);
console.log(fruit);
console.log(`First fruit in basket: ${fruit[0]}`);
console.log('Add fruit to end of the basket');
fruit.push('Strawberry');
console.log(fruit);
console.log('Add fruit to start of basket');
fruit.unshift('Mango');
console.log(fruit);
console.log('Removing a fruit from the basket');
console.log(`Removed: ${fruit.pop()}`);
console.log(fruit);
console.log('Is the console an array?');
console.log(Array.isArray(fruit));
console.log('Get index of first occuring fruit');
console.log(`Index of Pear: ${fruit.indexOf('Pear')}`);

//Object literals
//Key value pairs
const Person = {
    firstName: 'John',
    lastName: 'Smith',
    age: '22',
    address: {
        street: '138 Dabchick Road',
        suburb: 'Zeekoevlei'
    }
}
console.log(Person);
console.log(Person.address.street);
console.log('Extract information from object literals');
const {firstName, lastName} = Person;
console.log(firstName, lastName); //Seperate logs with commas
console.log('Add properties');
Person.mail = 'john@yahoo.com';
console.log(Person.mail);
console.log('Array of objects');
let todo = [
    {
        id: 0,
        task: 'Wash dishes'
    },
    {
        id: 1,
        task: 'Make bed'
    },
    {
        id: 2,
        task: 'Do homework'
    }
];
console.log(todo);
console.log(todo[0].id)
console.log(todo[0].task);

//JSON - similar tot object literals
const todoJSON = JSON.stringify(todo);
console.log(todoJSON);

//Loops
for(let c = 0; c < todo.length; c++) {
    console.log(`Task: ${todo[c].task}`);
}

let d = 1;
while (d <= 5) {
    console.log(`Step ${d} in while loop`);
    d++;
}

console.log('For-of loop');

for (let task of todo) {
    console.log(task.task);
}

//For-Each, maps and filters
//Uses call back functions
console.log('High order array methods');
todo.forEach(function(items) {
   console.log(items.task); 
});

//Map returns an array
const todoTask = todo.map(function(items) {
    return items.task;
});
console.log(todoTask);

//Filter - used to filter results from an existing array
//Returns a new filtered array
//Returns an element from n existing array thas satisfies a condition
const todoFiltered = todo.filter(function(items) {
    return items.task.length > 8;
});
console.log(todoFiltered);

//Conditionals
const a = 10;
// == , match the data types when checking
if (a == 10) {
    console.log('a = 10');
}
if (a == '10') {
    //will execute, using ==
    console.log('a = \'10\'');
}
//=== matches the data type
//Condtionals include || && !- etc
if (a === 10) {
    console.log('Number Match')
} else if (a === '10') {
    console.log('String match')
} else {
    console.log('Mismatch');
}

//Asign variables based on a condition - ternary
// ? = then
//condition ? true:false
const color = (x > 10) ? 'blue':'red';
console.log(color);

//functions
//Can set default values for params
function addNumbers(n1=1, n2=1) {
    return `${n1} + ${n2} = ${n1+n2}`;
}
console.log(addNumbers(3, 9));
console.log(addNumbers()); //will use default, otherwise returns NaN

//Arrow function ES6+
//assign var name = (params) => one-liner; Returns are implied
//assign var name = (params) => {function}; Returns are not implied
let subtNumbers = (n1,n2) => `${n1} - ${n2} = ${n1-n2}`;
console.log(subtNumbers(5,4));

//OOP ES5-
//Constructor functions, and methods
function People(fname, lname, dob) {
    this.fname = fname;
    this.lname = lname;
    this.dob = dob;
    this.getFName = function() {
        return this.fname;
    }
    
    this.getLName = function() {
        return this.lname;
    }
    
    this.getBirthYear = function() {
        return this.dob.substring(6,);
    }
}
//Instantiate object
const person1 = new People('John', 'Smith', '29/01/1998')
const person2 = new People('Mary', 'Smith', '29/01/1997');
console.log(person1.fname, person2.fname);
console.log(person1.getFName(), person1.getLName(), person1.getBirthYear());

//Prototypes
console.log(person1);
//Add functions to prototype
//Cleans up clutter inside 
function Student(firstName, lastName, id) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.id = id;
}
Student.prototype.getFirstName = function() {return this.firstName;}
Student.prototype.getLastName = function() {return this.lastName;}
const student = new Student('John', 'Smith', '19939868');
console.log(student.getFirstName());
console.log(student.getLastName());

//OOP ES6+
//Classes
class Car {
    constructor(make, model, vin) {
        this.make = make;
        this.model = model;
        this.vin = vin;
    }
    
    getMake() { return this.make; }
    getModel() { return this.model; }
    getVin() { return this.vin; }
}
const car = new Car('honda','civic','1234');
console.log(car);
console.log(car.getMake());

//DOM - Document Object Model

