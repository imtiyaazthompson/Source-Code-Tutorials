weight = float(input('How much do you weigh? '))
metric = input('(L)bs or (K)gs: ').lower()

if metric == 'l':
	print(f'Weight in kgs: {weight/2.205} kgs')
else:
	print(f'Weight in lbs: {weight*2.205} lbs') 