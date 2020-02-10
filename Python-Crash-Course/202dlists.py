#List where each item in the list is another list
matrix = [
	[1,2,3],
	[4,5,6],
	[7,8,9]
];

print(matrix)
for row in matrix:
	print(row);
	for item in row:
		print(item)
