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
