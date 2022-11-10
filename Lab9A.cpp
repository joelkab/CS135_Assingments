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
// getting doubel inputs

void getDoubleInputs(double &input1, double &input2);

double getDoubleInput(string, double, double);

bool checkFailure(double, double, double);

void addSubtract(double &, double &, double &Sub, double &add);

void multiplyDivide(double &num1, double &num2, double &Mult, double &Div);
// main functions
int main()
{

    double mult = 0.0;
    double Div = 0.0;
    double add = 0.0;
    double sub = 0.0;
    double input_1 = 0.0;
    double input_2 = 0.0;

    getDoubleInputs(input_1, input_2);
    addSubtract(input_1,input_2,sub,add);
    multiplyDivide(input_1,input_2,mult,Div);

    // calling the functions

    cout << fixed << setprecision(2);
    cout<<input_1<< " + "<<input_2 << " = "<< add<<endl;
    cout<<input_1<< " - "<<input_2 << " = "<< sub<<endl;
    cout<<input_1<< " * "<<input_2 << " = "<< mult<<endl;
    cout<<input_1<< " / "<<input_2 << " = "<< Div;

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
        cout << "Error: Invalid input!" << endl;
        // returns false if the input is not valid
        return false;
    }
    // returns true if the input is valid
    return true;
}
void getDoubleInputs(double &input1, double &input2)
{

    string promt = "Enter double between 0.500000 and 20.500000";
    string promt2 = "Enter another double between 0.500000 and 20.500000";
    double min = 0.500000;
    double max = 20.500000;
    double num1 = getDoubleInput(promt, min, max);
    double num2 = getDoubleInput(promt2, min, max);

    input1 = num1;
    input2 = num2;
}
void addSubtract(double &num1, double &num2, double &Sub, double &add)
{

    Sub = num1 - num2;
    add = num1 + num2;
}
void multiplyDivide(double &num1, double &num2, double &Mult, double &Div)
{
    Mult = num1 * num2;
    Div = num1 / num2;
}