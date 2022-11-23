/*
Name: Joel Kabura, 2001972424 #, 1006, LAB10A
Description: practice using basic input/output, creating a C++ struct, passing a struct to a
     function, saving data to andreading from a struct.
Input: Prompts the user to enter a thier first name, lastname and grade.
Output:  displasys the student first name, lastname and grade inlcuding the character grade.
*/
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstring>
using namespace std;

struct studentType
{
    string firstName;
    string lastName;
    int grade;
    char letterGrade;
};
void getStudentData(studentType &);
void getLetterGrade(studentType &);
void printStudentData(studentType);
bool checkFailure(int input, double min, double max);

int main()
{
    studentType info;

    getStudentData(info);
    getLetterGrade(info);

    printStudentData(info);
}

void getStudentData(studentType &student)
{
    int max = 4, min = 0;

    cout << "Enter a first name\n";
    cout << "**";
    cin >> student.firstName;
    cout<<endl;
    cout << "Enter a last name\n";
    cout << "**";
    cin >> student.lastName;
    cout<<endl;
    cout << "Enter a grade\n";
    cout << "**";
    cin >> student.grade;
    cout<<endl;

    while (checkFailure(student.grade, min, max) == false)
    {
        cout << "Enter a grade\n"
             << "**";
        cin >> student.grade;
        cout << endl;
    }
}
bool checkFailure(int input, double min, double max)
{
    if (cin.fail() || input < min || input > max)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Invalid grade" << endl;
        // returns false if the input is not valid
        return false;
    }
    // returns true if the input is valid
    return true;
}
void getLetterGrade(studentType &student)
{
    if (student.grade == 0)
    {
        student.letterGrade = 'F';
    }
    if (student.grade == 1)
    {
        student.letterGrade = 'D';
    }
    if (student.grade == 2)
    {
        student.letterGrade = 'C';
    }
    if (student.grade == 3)
    {
        student.letterGrade = 'B';
    }
    if (student.grade == 4)
    {
        student.letterGrade = 'A';
    }
}
void printStudentData(studentType student)
{
    cout << "Data Entered\n"
         << "  student.firstName   = " << student.firstName << endl
         << "  student.lastName    = " << student.lastName << endl
         << "  student.grade       = " << student.grade << endl
         << "  student.letterGrade = " << student.letterGrade << endl;
}