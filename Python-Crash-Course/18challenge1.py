symbol = [5,2,5,2,2]

for i in symbol:
	print('X' * i)

for i in symbol:
	output = ''
	for j in range(i):
		output += 'X'
	print(output)