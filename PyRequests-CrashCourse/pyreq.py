import requests
import json

response = requests.get('http://api.open-notify.org/astros.json')
json_response = response.json()
print(json_response)
print(type(json_response))

#Convert python json_response object into a string
def jprint(obj):
	text = json.dumps(obj, sort_keys=True, indent=4)
	print(text)


jprint(json_response)

#Using and API with query params
parameters = {
	"lat": 40.71,
	"lon": -74
}

response = requests.get('http://api.open-notify.org/iss-pass.json', parameters)
jprint(response.json())

#Understanding the response
#extract only the pass times from the JSON object
pass_times = response.json()['response']
jprint(pass_times)
rise_times = []

for d in pass_times:
	rise_times.append(d['risetime'])
print(rise_times)
