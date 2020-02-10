#Store information that come in key:value pairs
#Keys should be unique
customer = {
	"name": "John Smith",
	"age": 30,
	"is_verified": True
}

print(customer["name"]) #or, use get() method
print(customer.get("name"))

#add new keys
customer["dob"] = "Jan 1 1980"
print(customer["dob"])

numbers = {
	"0":"zero",
	"1":"one",
	"2":"two",
	"3":"three",
	"4":"four",
	"5":"five",
	"6":"six",
	"7":"seven",
	"8":"eight",
	"9":"nine"
}
phone = input('Phone: ')
output_str = ''
for char in phone:
	output_str += numbers[char] + " "
print(output_str)

