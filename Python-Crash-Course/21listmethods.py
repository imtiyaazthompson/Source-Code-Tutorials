numbers = [5,2,1,7,4]

#Append to end of list
numbers.append(20)
print(numbers)

#Insert item at index
numbers.insert(1, 15)
print(numbers)

#Remove an item from the list
numbers.remove(20)
print(numbers)

print('Clearing the list')
numbers.clear()
print(numbers)

for i in range(5):
	numbers.append(i)
print(numbers)
print('Pop an item from the back of the list')
popped = numbers.pop()
print('Current list {} and popped: {}'.format(numbers, popped))

#Index of first occurence of an item
print('Index of number 2, index: {}'.format(numbers.index(2))) 
print('Is 50 in the numbers list: {}'.format(50 in numbers)) #in operator

#Count occurences of an element in a list
print('3 appears: {} times in the list'.format(numbers.count(3)))

#Sort a list in-place
for j in range(5, 0, -1):
	numbers.append(j)
print(numbers)
numbers.sort()
print('Sorted list: {}'.format(numbers))
numbers.reverse()
print('Reverse sort: {}'.format(numbers))

#Create a copy of an existing list
numbers_copy = numbers.copy()
print(numbers_copy)
print(numbers)
numbers.pop()
print('Pop in original list: {}'.format(numbers))
print('Copied List: {}'.format(numbers_copy))
