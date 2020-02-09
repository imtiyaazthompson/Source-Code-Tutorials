is_driving = False
is_stopped = True

help = 'start - starts car, stop - stops car, quit - exit application'
prompt = input('>').lower()
while prompt != 'quit':
	if prompt == 'start' and is_stopped:
		is_driving = True
		is_stopped = False
		print('Car started, now driving')
	elif prompt == 'start' and is_driving:
		print('Car is already driving')
	elif prompt == 'stop' and is_driving:
		is_driving = False
		is_stopped = True
		print('Car is stopped')
	elif prompt == 'stop' and is_stopped:
		print('Car is already stopped')
	else:
		print('I do not understand')
	prompt = input('>').lower()
else:
	print('Thank You')