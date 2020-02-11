import requests
import json

def jprint(obj):
	print(json.dumps(obj, sort_keys=True, indent=4))

#Authenticating with API keys
#User-agent header
parameters = {
	"country":"south africa",
	"limit":10,
	"method":"geo.gettoptracks"
}

def lastfm_get(payload):
	headers = {
		"user-agent": "it2901"
	}
	url = 'http://ws.audioscrobbler.com/2.0/'
	payload['api_key'] = "659d72fedadc0142e12b272987aaac8e"
	payload['format'] = 'json'
	
	return requests.get(url, headers=headers, params=payload)

response = lastfm_get(parameters)
print(response.status_code)
jprint(response.json()['tracks']['track'])
