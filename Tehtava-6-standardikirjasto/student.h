#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Student
{
public:
    Student(string, int);
    ~Student();
    void setAge(int);
    int getAge();
    void setName(string);
    string getName();
    void printStudentInfo();
private:
    string Name;
    int Age;
};

#endif // STUDENT_H
