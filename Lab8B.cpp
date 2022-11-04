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
const double Pie = 3.141592;
// delcaring the functions
bool checkFailure(double, double, double);
double circumference(double);
double getDoubleInput(string, double, double);
double area(double);

// main functions
int main()
{
    // prompts
    string promt = "Enter a circle radius between 0.500000 and 20.500000";
    // min // max
    double min = 0.500000;
    double max = 20.500000;
    // storing the data from get doubel.
    double INPUT = getDoubleInput(promt, min, max);
    // calling the functions
    circumference(INPUT);
    area(INPUT);
}

// start of the functions

// getdouble
double getDoubleInput(string prompt, double min, double max)
{
    double NUM = 0.0;

    cout << prompt << endl
         << "**";
    cin >> NUM;
    cout << endl;

    while (checkFailure(NUM, min, max) == false)
    {
        cout << prompt << endl
             << "**";
        cin >> NUM;
        cout << endl;
    }

    // printing radius
    cout << fixed << setprecision(2) << "Radius: " << NUM << endl;
    // returns double num
    return NUM;
}

// check for failure
bool checkFailure(double input, double min, double max)
{

    if (cin.fail() || input < min || input > max)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Invalid radius!" << endl;
        // returns false if the input is not valid
        return false;
    }
    // returns true if the input is valid
    return true;
}
// finding the area
double area(double radius)
{
    double NUM = 0.0;
    NUM = (Pie * radius * radius);
    cout << fixed << setprecision(2) << "Area: " << NUM;
    // returns the area
    return NUM;
}

// find the circumference
double circumference(double radius)
{
    double NUM = 0.0;
    NUM = (2 * Pie * radius);
    cout << fixed << setprecision(2) << "Circumference: " << NUM << endl;
    // returns the circumference
    return NUM;
}
