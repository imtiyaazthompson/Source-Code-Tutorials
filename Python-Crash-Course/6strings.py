course = 'Python\'s crash course for beginners'
spanning_string = '''This is a string
		
		     That spans multiple

		     Lines.'''
indexing_string = 'Hello World, Again!'
negative_indexing = indexing_string
span_indexing = indexing_string
clone_string = indexing_string[:]
test_string = 'Jennifer'

print(course)
print(spanning_string)
print(indexing_string)
print('String character Indexing: ' + indexing_string[2] + indexing_string[3] + indexing_string[4])
print('Reverse string character indexing: ' + negative_indexing[-1] + negative_indexing[-2] + negative_indexing[-3])
print('[included : excluded]')
print('Spanning string indexing: ' + span_indexing[0:5])
print('Auto index spanning strings: ' + span_indexing[:9])
print('Cloning a string: ' + clone_string)
print(test_string[1:-1])

first = 'Imtiyaaz'
last = 'Thompson'
print('Formatted Strings: ')
fmt_string = f'{first} [{last}] is a coder'
print(fmt_string)