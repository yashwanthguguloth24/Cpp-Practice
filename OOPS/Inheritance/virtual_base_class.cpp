#include<iostream>
using namespace std;

/*
           class A(int a)
              |
              |
         ------------ 
         |          |
      class B      class C
         |          |
         |          | 
         ------------ 
              |
            class D
 class B and C are inherited from A and D is inherited from both B and C.
 Suppose there is a variable a then a is inherited to B and C. and when D is inherited from B and C 
 it has both the instances of 'a' which leads to ambiguity .
 So virtual base class is introduced.
 Example is given below:

class Student(int roll_no,void setRollno())
              |
              |
         ------------ 
         |          |
class TestScore   class SportScore
         |          |
         |          | 
         ------------ 
              |
      class Evalution
*/
class Student
{
    protected:
        int roll_no;
    public:
        void setRollno(int a)
        {
            roll_no = a;
        }

};

class TestScore : virtual public Student
{
    protected:
        float maths,physics;
    public:
        void setSubMarks(float a,float b)
        {
            maths = a;
            physics = b;
        }

        void printSubScores()
        {
            cout << "Maths :" << maths << endl;
            cout << "Physics :" << physics << endl;
        }
};

class SportsScore : virtual public Student
{
    protected:
        int pt_score;
    public:
        void setPtScore(int a)
        {
            pt_score = a;
        }

        void printPtScore()
        {
            cout << "Pt Score : " << pt_score << endl;
        }
};

class Evaluation : public TestScore , public SportsScore
{
    public:
        void printFinalScores()
        {
            printSubScores();
            printPtScore();
            cout << "Final Score : " << pt_score+maths+physics << endl;
        }
};


int main()
{
    //code goes here
    Evaluation s1;
    s1.setRollno(17);
    s1.setSubMarks(98.1,99.6);
    s1.setPtScore(10);
    s1.printFinalScores();
    return 0;
}
