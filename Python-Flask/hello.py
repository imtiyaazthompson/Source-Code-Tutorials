from flask import Flask, render_template
app = Flask(__name__) #name references the current file hello.py

'''
    Create an index route, so you do not 404 immediately when
    you browse to the URL
    @ - decorator
'''

'''
    Template Inheritance
    Create 1 master html file that contains the skeleton
    of what each page is going to look like that other
    subsequent pages can inherit from
'''
@app.route('/')
# Define a function for that route
def index():
    return render_template('index.html')

# If the program is run from this file __name__ == '__main__'
# Else if this file was imported by another file, __name__ != '__main__'
if __name__ == "__main__":
    # Start up the server
    app.run(debug=True)
