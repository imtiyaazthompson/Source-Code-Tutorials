for char in 'Python':
	print(f'Character: {char}')

for item in ['Apple', 'Banana', 'Orange', 'Pineapple']:
	print(f'Item in fruit basket: {item}')

print('range(including, excluding)')
print('range(from Zero upTo)')
print('range(including, excluding, increment)')
for step in range(1,5):
	print(f'Step {step} of stairs')
for step in range(1,20,2):
	print(f'Step {step} of stairs in jumps of 2')

shopping_cart = [10.0,20.0,30.0]
sum = 0
for price in shopping_cart:
	sum += price
print(f'Total Price: R{sum}')