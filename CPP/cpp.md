# Yay C++...the final chapter

## Hello World
```c++
	#include <iostream>

	int main()
	{
		std::cout << "Game Over!" << std::endl;
		return 0;
	}
```

+ `#include <iostream>` preprocessor directive
+ Preprocessor runs before the compiler and substitutes text based on various directives
+ The `#include` directive informs the preprocessot to include the contents of another file
+ `<iostream>` is a header file
+ `cout` is an object defined in the file `iostream` as well as `endl`
+ `<<` is the output operator
+ `cout` is prefixed with `std`.
	+ Tells the compiler to use `cout` from the `standar library`
	+ `std` is a namespace
	+ namespaces identifies the group to which something belongs
	+ Like (021) identifies that a number is calling from cape town
+ Since working with the `std` namespace is often used
	+ `using namespace std;` directly after the preprocessor directive

+ Or for specifiity make use of `using` declarations
	+ `using std::cout;`
	+ `using std::endl;`

## Fundamental Types
+ int,float,double,bool,char
+ type modifiers: short,long
+ for ints: signed, unsigned

### Variables and Input
+ Use `cin >> variable` to input a value into the variable
+ Then you know variable declarations, initialization etc
+ Constants `const <data type> <variable name>` used for magic numbers and the like
+ enums are a set of unsigned int constants
	+ `enum <enum type> {CONSTANT1, CONSTANT2, ...}`
	+ By default value of enums start at zero {CONSTANT1=0, CONSTANT2=1, ...}
	+ Values can be custom as well {CONSTANT1 = 25}
+ Create a variable of the enumeration type `<enum type> <name> = <CONSTANT_NAME>`
+ To use strings `#include <string>`, then `string <variable name>`

## Branching
```c++
	if (expression) {
		//execute if expression is true
	} else {
		//execute if expression is false
	}

	if (expression) {
	
	} else if (expression 2) {
		//execute if expression 2 is true but expression 1 is false
	} ... else {

	}
```

+ expressions use comparision operators to evaluate to a bool
+ ==,<=,<,>=,>
+ compound expressions with &&, ||

## Loops
```c++
	while (expression) {
		//execute until expression becomes false
		//don't forget loop counter
	}

	do {
		//Do some initial stuff
		//Keep doing stuff untill expression is false
	} while (expression);
```
+ `break` and `continue`
	+ `while (true)`
## Random Numbers
+ `#include <ctime>` for time
+ `#include <cstdlib>` for rand
+ Seed the random number generator: `srand(static_cast<unsigned int>(time(0)));`
+ Generate some random integer: `int randomNumber = rand();`
+ Minimize it to your range: `int die = (randomNumber % 6) + 1` -> get a number from 1 to 6
+ `static_cast<unsigned int>` converts/casts the value returned by time(0) -> returns current system time

## The Game Loop
+ Flow of events in a game
+ Consists of:
	+ Setup: Load resources
	+ Getting player input
	+ Taking into account player input, update game internals like physics enemy AI, game logic
	+ update display
	+ Check for game over state
	+ exit

## For Loops
```c++
	for (<loopcounter>; <expression>; <increment loop counter>) {
		//execute if true
	}
```

## Calm before the Storm - objects
+ Objects encapsulate data and functions
+ Data pertains to a certain object, like a car will have:`fuel_left`,`engine_type` etc
+ Functions that can work on the given encapsulated data: `get_fuel_left()`
+ `Object.member_data` or `Object.member_function()` 

### String objects
+ `#include <string>`
+ `using std::string`
+ Strings can be concatenated: `str1 + " " + str2;`
+ String length: `str.size()`
+ Character at position i: `str[i]`
+ Check if a string is empty: `str.empty()`
+ Return index of the first occurence of a substring: `str.find("substring")`
+ `string::npos` is returned when a substring is not found in a string, similar to an EOF
+ check if a substring exists, `if ("substring" != string::npos)` the substring exists
+ Erase a substring: `str.erase(<start pos>,<no. characters>)`
+ Erase all characters starting from pos n: `str.erase(n)`

## Arrays
+ Initialize an array of size n. Hold n elements of a certain type
```c++
	<data type> <variable name>[<integer size>];
	<variable name>[i] = <some value>;
```
+ Arrays with initialized with some values
	+ `int numbers[10] = {1,2,3};`
	+ First 3 elements of an array of size 10 initialized to 1,2,3

+ Get array size: `array.size()`

### Multidimensional Arrays
```c++
	<data type> <variable name>[ROWS][COLUMNS];
	<data type> <variable name>[ROWS][COLUMNS] = {
				{a,b,c,...},
				{},
				{},
				...
			};
```

## Standard Template Library
+ Provides a group of containers, algorithms and iterators

### Vectors
+ An STL container
+ Dynamic in size. Can grow
+ Vectors can be used with STL algorithms

```c++
	vector<data type> <variable name>;
	//Add elements to a vector
	<variable name>.push_back(<data of the same data type>);
	<variable name>[i];
	<variable name>.size();
	//Pop the last element of a vector off
	<variable name>.pop_back();
	<variable name>.clear();
```

+ STL in std namespace: `using std::vector`

### Iterators
+ Iterate through a sequence container
+ Iterator and const_iterator
+ Iterators allow you to refer to elements in a collection and even change the individual elements
+ const iterators also allow you to refer to elements in a collection but cannot change individual elements

```c++
	vector<string> inventory;
	vector<string>::iterator my_iter;
	vector<string>::const_iter iter;

	...

	for (iter = inventory.begin(); iter != inventory.end(); iter++) {
		cout << *iter;
	}
```

+ `inventory.begin()` signifies the position in the vector that is the beginning.
+ Set an iterator to refer to that element at the beginning position
+ Allow the iterator to iterate through the collection until it reaches the end of the collection
+ Dereference the iterator to display the value of what the iterator points to and not the iterator itself `*iter`
+ Make an iterator point to an item in the collection
+ `vector.end()` indicates the position after the last element in the vector

## STL Algorithms
