/*
Name: Jeol Kabura, 2001972424 , 1006, Assignment #1b - Hello, CodeGrade
Description:Uses a do...while loop to prompt the user to enter a count that is greater
    than 1 and less than or equal to 20 then reads
    in a count from the keyboard as an integer. and print out n of trangles.
Input: takes in aintergals
Output: draws n of trangles.
*/

// Preprocessor Directives

#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;
// getting the interger
int getIntegerInput(string promt, int numMin, int numMax, int &num)
{
do {
    cout << promt << endl
         << "**";
    cin >> num;
    if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Invalid entry, please retry" << endl;
            continue;
    }
            

}while (cin.fail()||num<numMin || num >numMax);


    

    return num;
}

// getting the character
char getCharacterInput(string prompt, char &charT)
{

    cout << prompt << endl
         << "**";
    cin >> charT;
    // returns the the character
    return charT;
}
// printing the upside down triangle
void writeUpsideDownTriangle(int size, char character)
{
    for (int i = 0; i < size; i++)
    {

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
    for (int i = 0; i < size; i++)
    {
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

int main()
{
    string promt = "Enter a count between 2 and 20";
    string char_promt = "Enter a character";
    char CHART = ' ';
    int NUM = 0, Min = 2, Max = 20;
    getIntegerInput(promt, Min, Max, NUM);
    getCharacterInput(char_promt, CHART);
    writeUpsideDownTriangle(NUM, CHART);
    writeRightsideUpTriangle(NUM, CHART);

    return 0;
}