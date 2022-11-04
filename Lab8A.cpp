/*
Name: Jeol Kabura, 2001972424 , 1006, LAB8A
Description: practice using basic input/output and making user defined functions.
Input: Calls a user defined functions named getintegarinput, getchracterinput,
     writedowTriangel and writeRightsideUptriangle.
Output: draws n of trangles.
*/

// Preprocessor Directives

#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;
int getIntegerInput(string, int, int);
char getCharacterInput(string);
void writeUpsideDownTriangle(int, char);
void writeRightsideUpTriangle(int, char);

int main()
{
    // adding values to both promt
    string promt = "Enter a count between 2 and 20";
    string char_promt = "Enter a character";
    int Min = 2, Max = 20;
    int NUM = getIntegerInput(promt,Min,Max);
    char CHART = getCharacterInput(char_promt);
    

    // calling the functions
    
    // functions for printing out the triangles
    writeUpsideDownTriangle(NUM, CHART);
    writeRightsideUpTriangle(NUM, CHART);
}
// getting the interger
int getIntegerInput(string promt, int numMin, int numMax)
{
    int num = 0;
    // a loop printing a promt and validating a the input
    do
    {
        cout << promt << endl
             << "**";
        cin >> num;
        cout << endl;
        // checking for a invalid input
        if (cin.fail() || num < numMin || num > numMax)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Invalid input!" << endl;
            continue;
        }

    } while (cin.fail() || num < numMin || num > numMax);

    return num;
}

// getting the character
char getCharacterInput(string prompt)
{
    char charT = ' ';
    // asking for the chracter
    cout << prompt << endl
         << "**";
    cin >> charT;
    cout << endl;
    // returns the the character
    return charT;
}
// printing the upside down triangle
void writeUpsideDownTriangle(int size, char character)
{
    // outside loop
    for (int i = 0; i < size; i++)
    {
        // inner loop
        for (int j = 0; j < size; j++)
        {
            if (i <= j)
            {
                cout << character;
            }
        }
        cout << endl;
    }
}
// printing rightsideuptriangle
void writeRightsideUpTriangle(int size, char character)
{
    // outside loop
    for (int i = 0; i < size; i++)
    {
        /// inner loop
        for (int j = 0; j < size; j++)
        {
            if (i >= j)
            {
                cout << character;
            }
        }
        cout << endl;
    }
}