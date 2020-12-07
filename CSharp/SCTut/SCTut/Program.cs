using System;

namespace SCTut
{
    class Program
    {
        static void Main(string[] args)
        {
            // Console.WriteLine("Hello World!");
            // Console.ReadLine();
            // ReadNames();
            // Car myCar = new Car("silver");
            // Console.WriteLine(myCar.Describe());
            //Console.ReadLine();
            Console.WriteLine(IsInt(1));
            Console.ReadLine();
        }

        static void ReadNames() {
            string fName;
            string lName;

            Console.WriteLine("Enter your first name: ");
            fName = Console.ReadLine();
            Console.WriteLine("Enter your last name: ");
            lName = Console.ReadLine();

            Console.WriteLine("Hello, " + fName + " " + lName + "!");
            Console.ReadLine();
        }

        static bool IsInt(Object value) {
            int v = (int)value;
            return value.GetType().Equals(typeof(int));
        }
    }

    class Car {
        private string color;

        public Car(string color) {
            this.color = color;
        }

        public string Describe() {
            return "This is a " + color + " car";
        }
    }
}
