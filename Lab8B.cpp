/*
Name: Joel Kabura, 2001972424 #, 1006, ASSIGNMENT_#2B
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
const double Pie = 3.141592;

bool checkFailure(double, double, double);
double circumference(double);
double getDoubleInput(string, double, double);
double area(double);

int main()
{
    // prompts
    string promt = "Enter a circle radius between 0.500000 and 20.500000";
    // min // max
    double min = 0.500000;
    double max = 20.500000;
    double INPUT = getDoubleInput(promt, min, max);
    // double Radius = ;
    double Circum = circumference(INPUT);
    double Area = area(INPUT);
}
double getDoubleInput(string prompt, double min, double max)
{
    double NUM = 0.0;
   
        cout << prompt << endl
             << "**";
        cin >> NUM;
        cout << endl;

        

     while (checkFailure(NUM, min,max) == false){
         cout << prompt << endl
             << "**";
        cin >> NUM;
        cout << endl;
     }

    // printing radius
    cout << "Radius: " << NUM << endl;
    return NUM;
}
bool checkFailure(double input, double min, double max)
{

    if (cin.fail() || input < min || input > max)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Invalid radius!" << endl;
        return false;
    }

    return true;
}

double area(double radius)
{
    double NUM = 0.0;
    NUM = (Pie * radius * radius);
    cout << fixed << setprecision(2) << "Area: " << NUM << endl;
    return NUM;
}
double circumference(double radius)
{
    double NUM = 0.0;
    NUM = (2 * Pie * radius);
    cout << fixed << setprecision(2) << "Circumference: " << NUM << endl;
    return NUM;
}
