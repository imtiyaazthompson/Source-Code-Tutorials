magic_number = 99
print('Guess the magic number!')
guess = int(input('Guess: '))
counter = 1

while guess != magic_number:
	guess = int(input(f'Guess again, last guess: {guess}, guess: '))
	counter += 1
print(f'You got it! You guessed right after {counter} attempts')

print('Lets play again! This time you only get 3 attempts')
counter = 0
limit = 3
magic_number = 100
while counter < limit:
	guess = guess = int(input('Guess: '))
	counter += 1
	if guess == magic_number:
		print(f'You won with {limit - counter} attempts left')
		break
	else:
		print('Try again...')
else:
	print(f'Tough stuff, try again another time, you wasted {limit} attempts')