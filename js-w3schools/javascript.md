# Learning JS

## Where
+ Embed javascript code in `<script> ... </script>`
+ Script tags can be placed within the `<head>` or `<body>`
+ JS function are invoked in response to events like a button click

## Output
+ JS can be outputted to an HTML element or the debug console or window alert
Examples
```javascript

	document.getElementById(id)
	window.alert("Alert")
	console.log("Log some stuff")
```

```html

	<p id="id"></p>
```
+ HTML elements are defined by their ID

```html
	<button type="button" onclick="document.getElementById('id').innerHTML = 'String'">Button</button>
```

+ To change the **inner html** of a tag, enclose the content in `' '` single quotes


## Variables

```javascript
	<script>
		var price1 = 10;
		var price2 = 20;
		var total = price1 + price2
		var subMsg = "The total is: "

		document.getElementById('button_1').innerHTML = subMsg + total;
	</script>

```

+ Think of datatypes as **Numbers** and **Strings**
+ Variables without a value will be declared with `undefined`
+ Adding `Numbers` to a `String` autoconverts the numbers to a string to be concatenated
	+ However the order matters
	+ `5 + 5 + "5"` -> `105`
	+ `"5" + 5 + 5` -> `555`

## Operators
### Comparison
+ `==` -> Compare equality with values
+ `===` -> compare equality with value and type 
+ `typeof`

## Datatypes revised
+ 3 types
	+ Numbers
	+ Strings
	+ Objects

```javascript

	var varNum = 29;
	var varStr = "i2901";
	var varObj = {username:varStr, age:varNum};
```

+ When adding a `Number` to a `String` the number will be treated as a string
+ Expression are evaluated from left to right
+ Booleans are `true` or `false`
+ Arrays
	+ Create an array with some items
```javascript
	
	var cars = ["Nissan","Toyota","Subaru"];
	cars.push("BMW");

```
+ `null` is and object whereas `undefined` is just `undefined`
+ Objects are name value pairs
```javascript

	var person = {name:"John",age:22};

```
+ Javascript objects can contain functions that define the behaviour of the object variables
```javascript
	var person = {
		name:"John",
		age:22,
		full:function() {
			return this.name + " is " + this.age + " years old.";	
		}
	};

	person.full() //Calls the function associated with the key: full
```

## Functions
```javascript
	function myFunc(args) {
		<code here>
		return something;
	}
```

## Events
+ Since javascript code is usually long and used in functions
+ Functions are mostly used in tandem with events to allow us to dynamically change the contents of the html

```javascript

	<p id='id_' onmouseover="change('id_')">I will change</p>


	<script>
		function change(id) {
			document.getElementById(id).innerHTML = "Changed"
		}
	</script
```

+ There are many more events that can be **reacted to** by javascript
|Event		|Description						|
|---------------|-------------------------------------------------------|
|onchange	| An HTML element has been changed			|
|onclick	| The user clicks an HTML element			|
|onmouseover	| The user moves the mouse over an HTML element		|
|onmouseout	| The user moves the mouse away from an HTML element	|
|onkeydown	| The user pushes a keyboard key			|
|onload		| The browser has finished loading the page		|


## String revisited
+ `var str = "Some String";`
+ Get string length -> `str.length;`
+ Lots of other methods that can becalled by `str.methodName();`

