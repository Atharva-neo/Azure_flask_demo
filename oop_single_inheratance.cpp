#include<iostream>
using namespace std;
class Human
{
    protected:
    string name;
    int age;
    ~Human()
    {
        cout<<"Hello Human\n";
    }
    public:
    void  Work()
    {
        cout<<"I am Working\n";
    }
};
class Student: public Human
    {
        int roll_no, fees;

        public:
        // Student(string name, int age, int roll_no, int fees)
        // {
        //     this->name = name;
        //     this->age = age;
        //     this->roll_no = roll_no;
        //     this->fees = fees;
        // }
    Student()
    {
        cout<<"Hello Student\n"; 
    }
    };
int main()
{
   Student S1;
   S1.Work();
}