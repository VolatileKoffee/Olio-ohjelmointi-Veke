#include "student.h"
#include <iostream>
using namespace std;

Student::Student(string word, int num):Name(word),Age(num)
{
    cout << "Student " << word << " with age " <<  num << " created! (constructor)" << endl; // debug code for student creation
}

Student::~Student() //destructor
{
    cout << "Student " << getName() << " with age " << getAge() << " destroyed! (destructor)" << endl;
}

void Student::setAge(int num)
{
    Age = num;
}

int Student::getAge()
{
    return Age;
}

void Student::setName(string word)
{
    Name = word;
}

string Student::getName()
{
    return Name;
}

void Student::printStudentInfo()
{
    cout << "Student: " << getName() << " Age: " << getAge() << endl;
}
