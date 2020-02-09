names = ['John', 'Bob', 'Sue', 'Mary']
print(names)
print(f'First name in list: {names[0]} and Last name in list: {names[-1]}')
print('Return new lists, no mod of old list')
print(f'Spanning names in list, middle 2 names: {names[1:3]}')
names[0] = 'Jon'
print(f'Mispell John: {names[0]}')

numbers = [19, 1, 2, 3, 11, 4, 27, 5, 6, 12, 7, 8, 9, 10]
print(f'Find the largest number in: {numbers}')
max = numbers[0]
for number in numbers:
	if number > max:
		max = number
print(max)