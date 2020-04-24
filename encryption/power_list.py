def powow(a,indices,mod):
	for index in indices:
		print("{}: {}".format(index,(a**index)%mod))

a = int(input("What's your a bro? "))
m = int(input("Number of indices chappy? "))
mod = int(input("Your mod china? "))
indices = []
for i in range(m):
	indices.append(i)

powow(a,indices,mod)
