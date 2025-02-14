#include <iostream>
#include <vector>
#include <algorithm>
#include "student.h"
using namespace std;


int main () {
    int selection = 0;
    int stuAge = 0;
    string stuName;
    string stuLookup;
    vector<Student>studentList; // Vektorin alustus
    Student stuObject(stuName,stuAge);

    do {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cout << "Selection: ";
        cin>>selection;

        switch(selection) {
        case 0:
            cout << "Enter student's name: "; // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            cin>>stuName;
            cout << "Enter student's age: ";
            cin>>stuAge;

            studentList.emplace_back(stuName,stuAge); // Lisää uusi opiskelija studentList vektoriin
            break;

        case 1:
            // Tulosta studentList vektorin kaikkien opiskelijat (nimi + ikä)

            cout << "Selection 1 success" << endl;

            for (auto& student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 2:
            /*  Järjestä StudentList-vektorin Student objektit nimen mukaan
                algoritmikirjaston sort -funktion avulla ja tulosta
                printStudentInfo() -funktion avulla järjestetyt opiskelijat */

            cout << "Selection 2 success" << endl;

            sort(studentList.begin(),studentList.end(), [](Student& a, Student& b){
                return a.getName() < b.getName();
            });

            for (auto& student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 3:
            /*  Järjestä studentList vektorin Student objektit iän mukaan
                algoritmikirjaston sort-funktion avulla ja tulosta
                printStudentInfo() -funktion avulla järjestetyt opiskelijat */

            cout << "Selection 3 success" << endl;

            sort(studentList.begin(),studentList.end(), [](Student& a, Student& b){
                return a.getAge() < b.getAge();
            });

            for (auto& student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 4:
            /*  Kysy käyttäjältä opiskelijan nimi. Etsi studentList
                opiskelijoista algoritmikirjaston find_if -funktion
                avulla löytyykö käyttäjän antamaa nimeä listalta.
                Jos löytyy, niin tulosta opiskelijan tiedot */
            {
            cout << "Selection 4 success" << endl;

            cout << "Search student by name: ";
            cin>>stuLookup;

            auto itr = find_if(studentList.begin(),studentList.end(),[stuLookup](Student& stu){return stu.getName() == stuLookup;});

            if (itr != studentList.end()) {
                cout << "Success!" << endl;
                cout << "Match found for student named '" << stuLookup << "' in the vector. Printing info..." << endl;
                itr->printStudentInfo();
            } else {
                cout << "Student named '" << stuLookup << "' was not found." << endl;
            }

            break;
            } // sulkeet luovat case 4:sta oman koodilohkonsa

        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
    } while (selection < 5);
    return 0;
}
