/*
Name: Joel Kabura, 2001972424 #, 1006, LAB9B
Description: in this lab you will practice using basic input/output,
    user defined functions, and function overloading.
Input: Prompts the user to enter 2 integer between 1 and 50 then reads an integer
    from the keyboard and 2 strings .
Output:  prints out both numbers added and multiplied. aswell as combinng both numbers.
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;
// delcaring the functions
// getting doubel inputs
void get_Inputs(int &input1, int &input2, string &str_input1,
                string &str_input2);
string getStringInput(string prompt);
bool checkFailure(double, double, double);
int add(int, int);
// string operator+(string s1,string s2);
int multiply(int, int);
// int operator+(string s, int count);
bool Str_checkFailure(string input);
// main functions
string operator*(string s, size_t count)
{
    string ret;

    for (size_t i = 0; i < count; ++i)
    {
        ret = ret + s;
    }
    return ret;
}
int main()
{

    int input_1 = 0;
    int input_2 = 0;
    string str_input1;
    string str_input2;

    get_Inputs(input_1, input_2, str_input1, str_input2);

    // addSubtract(input_1,input_2,sub,add);
    // multiplyDivide(input_1,input_2,mult,Div);

    // calling the functions

    cout << fixed << setprecision(2);
    cout << input_1 << " + " << input_2 << " = " << add(input_1, input_2) << endl;
    cout << str_input1 << " + " << str_input2 << " = " << str_input1 + str_input2 << endl;
    cout << input_1 << " * " << input_2 << " = " << multiply(input_1, input_2) << endl;
    cout << str_input1 << " * " << input_1 << " = " << str_input1 * input_1 << "\n";
    cout << str_input2 << " * " << input_2 << " = " << str_input2 * input_2 << "\n";
    return 0;
}

// start of the functions

// getdouble
int getDoubleInput(string prompt, double min, double max)
{
    int NUM = 0.0;

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
// get string
string getStringInput(string prompt)
{

    string input = " ";
    cout << prompt << endl
         << "**";
    cin >> input;
    cout << endl;

    while (Str_checkFailure(input) == false)
    {
        cout << prompt << endl
             << "**";
        cin >> input;
        cout << endl;
    }
    return input;
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
// string erorr checking
bool Str_checkFailure(string input)
{

    if (cin.fail())
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
void get_Inputs(int &input1, int &input2, string &str_input1, string &str_input2)
{

    string promt = "Enter an integer between 1 and 50";
    string promt2 = "Enter another integer between 1 and 50";
    string str_promt = "Enter a string";
    string str_promt2 = "Enter another string";

    int min = 1;
    int max = 50;
    input1 = getDoubleInput(promt, min, max);
    input2 = getDoubleInput(promt2, min, max);
    str_input1 = getStringInput(str_promt);
    str_input2 = getStringInput(str_promt2);
}

int add(int num1, int num2)
{
    int add = 0;
    add = num1 + num2;
    return add;
}

int multiply(int num1, int num2)
{
    int mult = num1 * num2;
    return mult;
}

// multiply