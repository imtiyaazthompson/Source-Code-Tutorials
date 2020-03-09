# Always create an application instance
from flask import Flask, request, current_app
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

# Flask makes use of different contexts to get access to certain
# Variables
# If you are in the request context, you get access to the
# request object, which encapsulates the request from the client
# over HTTP
# Here request is used as a global variable but it is not
# Since it is only made available to the current thread handling
# the request and we are in the request context
# Don't forget to import request
@app.route('/reqctx')
def ctx():
    usr_agent = request.headers.get('User-Agent')
    return '<p>Browser: {}</p>'.format(usr_agent)

# Another context the flask app can work in is the application ctx
# While in app ctx we do not have access to the request variable
# Since we are not in the request context
# Don't forget to import current_app
# Obtain app context with app.app_context()
# Then push the context to get access to the current_app
# Variable available to the thread
# Pop to exit out of the appl context
@app.route('/appctx')
def actx():
    app_ctx = app.app_context()
    app_ctx.push()
    curr_name = current_app.name
    app_ctx.pop()
    return 'Application Context, app name: {}'.format(curr_name)

# Remember, every request sent by the client requires
# a view function to service that request
# That is handled by the routes you create for each request
# the route to a specific link/request requires a view function
# to service it, every route requires a function


# Run the server in debug mode
# localhost:5000/
if __name__ == '__main__':
    app.run(debug=True)
