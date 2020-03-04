# Always create an application instance
from flask import Flask
app = Flask(__name__)

# Requests must be handled by a block of code
# Application instance maps URLs to python functions via Routes
# Think of a URL as a request for an html, web app, db entry etc

@app.route('/')
def index():
    return '<h1>Hello World</h1>'

# Routes pair requests with funstions to handle that Requests
# Functions must return a response to the client

# Handling dynamic URLs
@app.route('/user/<name>')
def user(name):
    return 'Hello, {}'.format(name)

# Dynamic components in URLs can also be defined by a type
# <[int|float|path]:string>
app.route('/user/<int:id>')
def user_id(id):
    return 'Your UID: {}'.format(id)

# Run the server in debug mode
# localhost:5000/
if __name__ == '__main__':
    app.run(debug=True)
