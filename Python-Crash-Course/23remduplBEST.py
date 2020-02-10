sequence = []
unique = []
for i in range(10):
	sequence.append(i)
	sequence.append(i)
	sequence.append(i)

for number in sequence:
	if number not in unique:
		unique.append(number)
print(sequence)
print(unique)
