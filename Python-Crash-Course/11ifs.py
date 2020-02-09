is_hot = True
is_cold = False

if is_hot:
	print('Drink plenty of water')
elif is_cold:
	print('Wear a jacket')
else:
	print('Still drink enough water!')

cost = 1000000
good_credit = False
down_pay = 0

if good_credit:
	down_pay = cost*0.1
else:
	down_pay = cost*0.2
print(f'Down payment: R{down_pay}')

has_good_credit = False
has_high_income = False

if has_good_credit and has_high_income:
	print('Cool!')
elif has_good_credit or has_high_income:
	print('Not that cool')
elif not has_good_credit and not has_high_income:
	print('Uncool')

temp = float(input('Enter a temp: '))
if temp > 25:
	print('Gonna be a hot day')
elif temp < 12:
	print('Gonna be a cold day')
else:
	print('Gonna be a good day')

username = input('Input a username: ')
ulen = len(username)
if ulen < 10:
	print(f'Username is too short, username length: {ulen}')
elif ulen > 50:
	print(f'Username is too long, username length: {ulen}')
else:
	print(f'Username accepted, username length: {ulen}')