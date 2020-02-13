import re

#Auto close file
with open('test.html') as f_obj:
	text = f_obj.read()

#Find everything (.*?)
#.   - any character except for \n
#.*  - 0 or more reps of any character except for \n
#.*? - 0 or 1 matches for 0 or more reps of any character except for \n
paragraphs = re.findall(r'<p\sclass="css-exrw3m evys1bk0">(.*?)</p>', text)
print(paragraphs) 
