#include<iostream>
using namespace std;

// Example of multilevel inheritance
/*

Multilevel inheritance
Student -> Exam -> result .

*/
// student class
class Student
{
    protected:
        int student_rollno;
    public:
        void setRollno(int);
        void getRollno(void);
};

void Student :: setRollno(int a)
{
    student_rollno = a;
}

void Student :: getRollno()
{
    cout << "Student roll no : " << student_rollno << endl;
}

// exam class
class Exam : public Student
{
    public:
        float math_marks;
        float phy_marks;
        void setMarks(float a,float b)
        {
            math_marks = a;
            phy_marks = b;
        }

        void getMarks(void)
        {
            cout << "Math Marks : " << math_marks << endl;
            cout << "Physics Marks : " << phy_marks << endl;
        }
};


class Result : public Exam
{
    protected:
        int percentage;
    public:
        void DisplayResult()
        {
            getRollno();
            getMarks();
            percentage = (math_marks+phy_marks)/200;
            percentage = percentage*100;
            cout << "Percentage : " << percentage << "%" << endl;
        }

};


int main()
{
    Result yashwanth;
    yashwanth.setRollno(17);
    yashwanth.setMarks(100.0,100.0);
    yashwanth.DisplayResult();
    return 0;
}

