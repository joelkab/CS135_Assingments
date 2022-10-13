/*
Name: Jeol Kabura, 2001972424 , 1006, Assignment #1b - Hello, CodeGrade
Description: prints out the exact same code as the description
Input: takes in 2 intergals a and b. takes two doubles x and y.
Output: 12 + 9 = 21
12 - 9 = 3
12 * 9 = 108
12 / 9 = 1
12 % 9 = 3
*/

// Preprocessor Directives

#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

int Print_Macthes(int Remove, int &MATCHES)
{

    MATCHES = MATCHES - Remove;
    for (int i = 0; i < MATCHES; i++)
    {
        if (i % 5 == 0)
        {
            cout << " ";
        }
        cout << "|";
    }

    return 0;
}
int Com_turn(int &P_MATCHES, int &calculation)
{
    calculation = P_MATCHES % 4;

    return calculation;
}

int main()
{

    char yes_no;
    int Num_remove = 0, Com_remove = 0, MATCHES = 21;

    cout << "The game of Nim.  The player to remove the last match loses." << endl
         << endl;
    cout << "Would you like to go first? (Y/N):";
    cin >> yes_no;

    do
    {

        // handling user input
        switch (yes_no)
        {
        case 'Y':
        case 'y':
            cout << "Player Turn - Matches:";
            // for loop
            for (int i = 0; i < MATCHES; i++)
            {

                if (i % 5 == 0)
                {
                    cout << " ";
                }
                cout << "|";
            }
            // end of for loop
            cout << endl;
            cout << "Remove (1 - 3):";
            cin >> Num_remove;
            // validating
            if (cin.fail() || Num_remove > 3 || Num_remove < 1)
            {
                cout << "Please, type 1, 2, or 3 as your response.";
                return 0;
            }

            break;
        case 'N':
        case 'n':
            cout << "you entered Y";
            break;

        default:
            cout << "Please, answer Y or N.";
            break;
        }
        // computer turn
        while (MATCHES > 1)
        {

            cout << "Computer Turn - Matches:";
            // calling player_trun function

            Print_Macthes(Num_remove, MATCHES);

            cout << endl;
            cout << MATCHES << endl;
            cout << "Computer removes";

            Com_turn(MATCHES, Com_remove);

            cout << Com_remove <<"."<<endl;
            // player turn
            cout << "Player Turn - Matches:";
            Print_Macthes(Com_remove, MATCHES);

            cout << endl;

            cout << MATCHES << endl;

            cout << "Player Turn - Matches:";
            cout << endl;
            cout << "Remove (1 - 3):";
            cin >> Num_remove;
        }

    } while (cin.fail());

    return 0;
}