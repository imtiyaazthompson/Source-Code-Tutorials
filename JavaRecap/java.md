# Simple declarations
```java

	int m,n;
	double x,y;
	boolean b;
	char ch;
```

# Numeric expressions and assignments
```java

	n = 3 * (5 + 2);
	etc
```

# Type Conversion
+ (type) [variable|expression];

# Statements
+ if - else if - else
+ while
+ for loop

All follow C syntax

# Classes and objects
+ One file normally contains one class

## Classes
+ Contains instance variables and methods
+ Attributes and Actions

```java

	class Turtle {
		private boolean penDown;
		protected int x,y;
	}
```

+ Private variables cannot be accessed outside of a class they are declared in
+ Protected variables can be accessed within the class and subsequent subclasses but not outside of the class it was declared in

## Methods
```java

	class Turtle {

		// Attributes here

		public void jumpTo(int nX, int nY) {
			x = nX;
			y = nY;
		}

		public int getX() {
			return x;
		}
	}
```

# Using objects
+ `new` operator is used to create objects for a given class
```java

	Turtle t = new Turtle(1,2);
	int a = t.getX();
```
+ t is a reference variable to the Turtle object

# Constructors
+ Automatically called when a new object is created

```java
	class Turtle {

		// Attributes here

		public Turtle(int initX,int initY) {
			x = initX;
			y = initY;
			penDown = false;
		}
	}

```

# The `main` Method
+ Method called by the system when the program starts executing
+ Creates a few objects and gets the program started

```java

	public static void main(String[] args) {
		Turtle t = new Turtle(1,2);
		t.right(90);
		while (t.getX() < 180) {
			t.forward(2);
		}
	}
```

+ Because the main method is declared as static it cannot access any attributes (instance variables)

+ args = paramaters given other than the class name when running the program from the cmd

# Inheritance
+ Use the `extends` keyword to declare a subclass of another class

```java

	class NinjaTurtle extends Turtle {
		// Declarations for NinjaTurtles
	}

```
+ A method in a class automatically overrides any method with the same name and params in any superclass
+ Abstract methods = methods without any implementation
+ A subclass wil ldefine the implementation of an abstract method
```java 

	public abstract void draw();
```


# Interfaces and Listeners
+ Interfaces specify that a class has to provide a certain set of methods

Example:
+ GUIs need to be informed whenever a mouse is clicked
+ Suppose the window implements an interface:

```java
	
	interface MouseListener {
		void processMouseClick(int x, int y);
	}
```

+ If an object should be used to handle mouse clicks it must implement the method found in the interface exactly
+ A class is declared to implement that interface

```java

	class Mouse extends Rodent implements MouseListener {
		// declarations


		void processMouseClick(int x,int y) {
			// Do something
		}
	}
```

# Exceptions
## Catching Exceptions
```java

	try {
		// Stuff to try
	} catch (Exception e) {
		// Stuff if an error occurs
	}
```

## Throwing Exceptions
```java

	public int getNatural() throws IOException {
		char ch;
		while (condition) {
			ch = readChar();
			if (ch < '0' || ch > '9') {
				throw new IOException("bad number")
			}
		}
	}
```

## Declaring new exceptions
+ Create a subclass of the `Exception` class
```java

	class OverheatedException extends Exception {
		public OverheatedException(String s, double tmp) {
			super(s);
			myTemperature = tmp;
		}

		public double getTemp() {
			return myTemp;
		}

		private double myTemp;
	}
```

# Using Packages
+ Packages must be imported
+ `import java.awt.*;`

# Arrays
+ `dataType[] myArray = new dataType[N];`
