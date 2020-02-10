def greet_user():
	print('Hello, World!')
	print('New adventures...')


print('Start')
greet_user()
print('End')

#Paramaters
def greet_user(name, age):
	print('Hello {} of {} years'.format(name,age))


greet_user('John',30)


#Returns
def square(n1):
	return n1*n1


print(square(10))
