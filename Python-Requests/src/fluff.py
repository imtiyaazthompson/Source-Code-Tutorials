import requests
from requests.exceptions import HTTPError

#Making a GET request
#You make a request and get a response
#Response codes indicate what that response was
response = requests.get('https://api.github.com')
print(type(response))

#200 Status code means the request was successful, 404 not found
response_status = response.status_code
print(f'Response returned code: {response_status}')

for url in ['https://api.github.com', 'https://api.github.com/invalid']:
    try:
        response = requests.get(url)
        #If response was successful, no Exception will be raised
        response.raise_for_status()
    except HTTPError as http_err:
        print(f'HTTP error occurred: {http_err}')
    except Exception as err:
        print(f'Some other error occurred: {err}')
    else:
        print('Success!')

response = requests.get('https://api.github.com')
response.encoding = 'utf-8'
payload = response.text
#Convert serialized json into a dictionary
json_dict = response.json()
print(json_dict)

#Response Headers
#Metadata
#Keys are case insensitive
print(response.headers)

#Query Strings
response = requests.get(
    'https://api.github.com',
    params={'q': 'requests+language:python'},)

json_response = response.json()
print(json_response)
repo = json_response['items'][0]
print(repo)