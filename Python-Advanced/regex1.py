import re as regex

"""
Identifiers

\d - Any single character or number
\D - Anything but a number (non-digit character)
\s - Space
\S - Anything but a space
\w - Any character (A-Z, a-z, 0-9 and unders­core)
\W - Anything but a character
.  - Any single character except for a new line
\b - The white space around words
\. - A period
"""	
"""
Modifiers

{x,y} - We expect x to y integers
+     - Match one or more occurr­ences
?     - Match 0 or 1 occurrence
*     - Match 0 or more of the preceding expression (eg. x* will match occurrences of x)
$     - Match the end of the string
^     - Matching the beginning of a string
|     - Used as OR
[]    - Displaying a range
()    - To group the regular expressions
"""
"""
Methods

match()   - Syntax - re.mat­ch(­pat­tern, string, <fl­ag=­0>)
	    search()
	
	  - For any pattern in the string - only the first match
findall() - Matches all occurrences
split()   - Splits the string - forms an array
replace() - To replace one or more characters in a string
"""


example_str = '''Jessica is 15 years old, and Daniel is 27 years old.
		Edward is 97, and his grandfather, Oscar, is 102.'''

age_regex = regex.findall(r'\d{1,3}', example_str) #find any digits 1 - 3 in length
#Find words that start with capital, followed by 0 or more occurences of lower case letters
name_regex = regex.findall(r'[A-Z][a-z]*', example_str)

print(age_regex)
print(name_regex)

info = {}
for name in name_regex:
	info[name] = age_regex[name_regex.index(name)]
print(info)
