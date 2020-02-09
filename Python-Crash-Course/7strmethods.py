course = 'Python for beginners'
print(f'Course string length: {len(course)}')
print(f'Original string: {course}')
print(f'String to uppercase (Create new, No mod): {course.upper()}')
print(f'String to lowercase (Create new, No mod): {course.lower()}')
print(f"Index of first occurence of 'o': {course.find('o')}")
print(f'Index of start of "for": {course.find("for")}')
print(f'Replace: "beginners" with: "Absolute Beginners" ==> {course.replace("beginners", "Absolute Beginners")}')
print(f'Does "Absolute Beginners" exist in the course string now? {"Absolute Beginners" in course}')