# Hello World
```C#
	using System;
	using System.Collections.Generic;
	using System.Linq;
	using System.Text;
	using System.Threading.Tasks;

	namespace ConsoleApp {
		class Program {
			static void Main(string[] args) {
				Console.WriteLine("Hello, world!");
				Console.ReadLine();
			}
		}
	}
```

+ Write to console
+ Then read from console to stop the application from immediately closing

# Facts: Hello World
+ A `namespace` is a collection of classes

# Variables
+ `<visibility> <data type> <name> = <value>;`

```C#
	static void Main(string[] args) {
		string fName;
		string lName;

		Console.WriteLine("Enter your first name: ");
		fName = Console.ReadLine();
		Console.WriteLine("Enter your last name: ");
		lName = Console.ReadLine();

		Console.WriteLine("Hello, " + fName + lName + "!");
		Console.ReadLine();
	}
```

+ Reading numbers from the command line
```C#
	int number = int.Parse(Console.Readline());
```

+ Accessing variables from class scope
```C#
	class Program {
		private static string hello = "hello class!";

		static void Main(string[] args) {
			Console.WriteLine(Program.hello);
		}
	}
```

+ Datatypes
	+ `bool`: true/false
	+ `int`: real number
	+ `string`: string of characters
	+ `char`: single character
	+ `float`: decimal numbers

# Branching
+ `if else` follows from java
+ `switch` follows from java, able to switch on string values

# Loops
+ `while` follows from java
+ `do while` follows from java
+ `for` follows from java

# Foreach loops and ArrayLists
```C#
	ArrayList list = new ArrayList();
	list.Add("John");
	list.Add("Smith");
	list.Add("Sue");

	foreach(string name in list) {
		Console.WriteLine(name);
	}
```

# Classes
```C#
	class Program {
		static void Main(string[] args) {

		}
	}
	
	class Car {
		private string color;

		public Car(string color) {
			// constructor
			this.color = color;
		}

		public string Describe() {
			return "This is a " + color + " car";
		}
	}
```

# Class Properties
+ Field setters and getters
```C#
	class Car {
		private string color;


		public string Car {
			get {
				return color;
			}

			set {
				color = value;
			}
		}
	}
```

# Methods and Functions
+ `<visibility> <return type> <name>(<params>) { <code> }`
+ Optional/Default parameters like in python
+ Allowing many number of parameters
```C#
	public void Greet(params string[] names) {}
```

# By Value
+ Arguments are passed into methods `by value`
+ Meaning that you send a copy of the object instead of a reference to it
+ Change the param of an object without affecting the original
+ To use pass by reference
```C#
	public void DoSomething(ref int number) {}
```

# Static classes
+ Like a toolbox
+ A class that does not need to be instantiated

# Inheritance
```C#
	public class Animal {
		public virtual void Greet() {
			Console.WriteLine("Hello, I am an animal!");
		}
	}


	public class Dog: Animal {
		public override void Greet() {
			Console.WriteLine("Hello, I am a dog!");
		}
	}
```
+ `Dog` class inherits all the fields and methods from the `Animal` class
+ The `Dog` class can only override a method from the `Animal` class if it is marked as virtual
+ A puppy class can inherit from `Dog`, which inturn inherits from `Animal`
+ However, one class cannot inherit from several classes at the same time

# Abstract Classes
+ Define a base class in a heirarchy
+ You cannot create an instance of an Abstract class
+ Abstract classes have to be subclassed, then create an instance of the subclass
+ Abstract classes are useful for frameworks
```C#
	abstract class FourLegs {
		public virtual string Describe() {
			return "This is a four legged animal";
		}
	}
```
+ Sometimes you want to use behaviour from the base class in addition to new functionality you override in the ineriting class
```C#
	class Dog: FourLegs {
		public override string Describe() {
			string result = base.Direction();
			result += " I am also a dog!";
			return result;
		}
	}
```
+ Abstract methods are only allowed within abstract classes
+ Looks like a normal methods definition but will have no code inside them
```C#
	abstract Class FourLegs {
		public abstract string Describe();
	}
```
+ Abstract methods are obligations to implement that very method in all subclasses
+ We can use the base class as a type cast in functions since its subclasses must implement its abstract methods

# Interfaces
+ Abstract classes but with only abstract methods
+ Act as a contract


320 + 20 + 40