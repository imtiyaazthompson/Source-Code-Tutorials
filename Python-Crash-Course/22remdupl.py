sequence = []
for i in range(10):
	sequence.append(i)
	sequence.append(i)
sequence.append(2)
sequence.append(7)
print('Sequence with duplicates: {}'.format(sequence))

for number in sequence:
	occ = sequence.count(number)
	for t in range(occ - 1):
		sequence.remove(number)
print(sequence)
