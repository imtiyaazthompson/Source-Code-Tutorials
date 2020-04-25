# My list of C-tricks
## 1 - OOP In C
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student;
typedef struct student Student;

//Class definition
struct student {
        char name[50];
        //Will be set to a callback function
        void (*get_name)(Student *this);
};

//Actual method-function
void to_string(Student *this) {
        printf("SN: %s\n",this->name);
}

//Constructor
Student* cStudent(char *n) {
        Student *nStudent = malloc(sizeof(Student));
        strncpy(nStudent->name,n,sizeof(char)*50);
        nStudent->get_name = to_string;
        return nStudent;
}

int main(int argc, char **argv) {
        //Create instance of Student Class
        Student *bob = cStudent("Bob Sagat");
        bob->get_name(bob);
        return 0;
}

```
