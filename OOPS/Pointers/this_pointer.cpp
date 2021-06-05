#include<iostream>
using namespace std;


class Student
{
    public:
        int rollno;
        float marks;
        // use this-> variable when both variable and arguments are same
        Student(int rollno,float marks)
        {
            this->rollno = rollno;
            this->marks = marks;
        }
        // "this" pointer is similar to self in python
        // this points to the object from which it is invoked
        // Below is one of the instances where we can use this pointer.
        Student * CompareMarks(Student &s1)
        {
            if(s1.marks > this->marks)
            {
                Student *ptr = &s1;
                return ptr;
            }
            else
            {
                return this;
            }
        }
};

int main()
{
    Student s1(1,66.5);
    Student s2(2,99.0);
    Student* temp = s1.CompareMarks(s2);
    cout << temp->rollno << endl;
    return 0;
}
