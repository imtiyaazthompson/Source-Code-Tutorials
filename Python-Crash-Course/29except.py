try:
	age = int(input('Age: '))
	print(age)
except ValueError:
	#What happens in case of an error
	print('Invalid input')
