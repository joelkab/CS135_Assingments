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

int getIntegerInput(string promt, int numMin, int numMax)
{
    int num = 0;
    cout << promt;
    cin >> num;
    
    do { 
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error: Invalid entry, please retry" << endl;
        // cout << promt;
        // cin >> num;
        continue;
    }while (cin.fail() || num <numMin && num >numMax);

    return num;
}
char getCharacterInput(string prompt,char &charT){
    
    cout<<prompt<<endl<<"**";
    cin>>charT;

    return charT;
}

int main()
{
    int n = 0;

    do
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10, '\n');
            continue;
        }

        cout << "Enter a count between 2 and 20" << endl
             << "**";
        cin >> n;
        cout << endl;
        /// checking for correct input
        if (n >= 2 && n <= 20)
        {
            // first for loop
            for (int i = 0; i < n; i++)
            {

                for (int j = 0; j < n; j++)
                {
                    if (i <= j)
                    {
                        cout << "*";
                    }
                }
                cout << endl;
            }
            // secound forloop
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i >= j)
                    {
                        cout << "*";
                    }
                }
                cout << endl;
            }
            // if input is wrong
        }
        else
        {
            cout << "Error: Invalid entry, please retry" << endl;
        }
        // if input is incorrect or fails
    } while (cin.fail() || n < 2 || n > 20);

    return 0;
}