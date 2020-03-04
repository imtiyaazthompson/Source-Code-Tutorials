 # Use classes to define new types to model different things
class Point:
    # Here we define all the functions and methods that
    # Belong to the Point class
    # Classes can have attributes that belong to objects
    # of that class

    # A constructor is a function that gets called
    # at the time of creating an object
    # Self is a reference to the current object
    def __init__(self, x, y):
        self.x = x
        self.y = y


    def move(self, dx, dy):
        print('Moving...')
        self.x = self.x + dx
        self.y = self.y + dy


    def draw(self):
        print('({}, {})'.format(self.x, self.y))



# Create new object of type Point
# An object is an instance of a class
# Class defines a template for creating objects
# Objects are instances based on the class template
point = Point(10.0,20.0)
point.draw()
point.move(2,-4)
point.draw()
#point_0.x = 10.0
#print(point_0.x)
