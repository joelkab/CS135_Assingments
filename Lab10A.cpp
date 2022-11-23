/*
Name: Joel Kabura, 2001972424 #, 1006, LAB8B
Description: Prompts the user to enter a radius and reads in a radius from the keyboard as a double.
    prints Calculated circumference of a circle and Calculated area of a circle.
Input: Prompts the user to enter a radius and reads in a radius from the keyboard as a double.
Output:  prints Calculated circumference of a circle and Calculated area of a circle.
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
}

void getStudentData(studentType &)
{
    int max = 4, min = 0;
    studentType info;

    cout << "Enter a first name\n";
    cout << "**";
    cin >> info.firstName;
    cout << "Enter a last name\n";
    cout << "**";
    cin >> info.lastName;
    cout << "Enter a grade\n";
    cout << "**";
    cin >> info.grade;
    
    while (checkFailure(info.grade,min,max) == false)
    {
          cout << "Enter a grade\n"
             << "**";
        cin >> info.grade;
        cout << endl;
    }

    cout << "first name " << info.firstName << " last name: " << info.lastName << "grade: " << info.grade;
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
void getLetterGrade(studentType &){
        studentType info;
        if(info.grade == 0){
            info.letterGrade = 'F';
        }
        if(info.grade == 1){
            info.letterGrade = 'D';
        }
        if(info.grade == 2){
            info.letterGrade = 'C';
        }
        if(info.grade == 3){
            info.letterGrade = 'A';
        }
    }