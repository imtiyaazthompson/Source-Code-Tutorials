try:
	age = int(input('Age: '))
	print(age)
except ValueError:
	#What happens in case of an error
	print('Invalid input')
# Can use multiple excepions to handle vrious other exceptions that might
# Occur in the prog
