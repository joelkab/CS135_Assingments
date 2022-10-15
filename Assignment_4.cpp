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
#include <cstring>

using namespace std;

int Print_Macthes(int &Remove, int &MATCHES)
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

    if (calculation == 0)
    {
        calculation = 3;
    }
    else if (calculation == 1)
    {
        calculation = 1;
    }
    else if (calculation == 3)
    {
        calculation = 2;
    }
    else if (calculation == 2)
    {
        calculation = 1;
    }

    return calculation;
}

int main()
{

    char yes_no;
    char again = ' ';
    bool playagin = false, showSwitch = true;
    int Num_remove = 0, Com_remove = 0, MATCHES = 21;

    cout << "The game of Nim.  The player to remove the last match loses." << endl
         << endl;
    cout << "Would you like to go first? (Y/N):";
    cin >> yes_no;
    do
    {
        
        if (playagin == true)
        {
            cout << "Would you like to go first? (Y/N):";
            cin >> yes_no;
            playagin = false;
        }

        if (showSwitch == true)
        {
            // handling user input
            switch (yes_no)
            {
            case 'Y':
            case 'y':

                break;
            case 'N':
            case 'n':
                // computer turn
                cout << "Computer Turn - Matches:";
                Print_Macthes(Com_remove, MATCHES);
                cout << endl;
                // n
                cout << "Computer removes ";
                Com_turn(MATCHES, Com_remove);

                cout << Com_remove << " ." << endl;
                showSwitch = false;
                break;

            default:
                cout << "Please, answer Y or N."<<endl;
                break;
            }
        }
        // player goes first

        cout << "Player Turn - Matches:";

        Print_Macthes(Com_remove, MATCHES);

        // checking if matches is equal to 1 then the computer wins 
        if (MATCHES == 1)
        {
            cout << endl;
            cout << endl;
            cout << "Game Over - Computer wins." << endl;
            cout << endl;

            cout << "Would you like to play again? (Y/N):";
            cin >> again;

            switch (again)
            {
            case 'y':
            case 'Y':
                cout << "you entered yes" << endl;
                MATCHES = 21;
                playagin = true;
                showSwitch = true;
                continue;

            case 'N':
            case 'n':
                return 0;

            default:
                break;
            }
            continue;
        }
        // end of switch
        cout << endl;
        cout << endl;
        cout << "Remove (1 - 3):";
        cin >> Num_remove;

        // validating
        if (cin.fail() || Num_remove > 3 || Num_remove < 1)
        {
            cin.clear();

            cout << "Please, type 1, 2, or 3 as your response." << endl;
            break;
        }
        // computer turn
        cout << "Computer Turn - Matches:";

        // calling player_trun function

        Print_Macthes(Num_remove, MATCHES);
        cout << endl;
//checking if the player has won
        if (MATCHES == 1)
        {
            cout << endl;
            cout << endl;
            cout << "Game over - Player wins." << endl;
            cout << endl;

            cout << "Would you like to play again? (Y/N):";
            cin >> again;
            cin.clear();

           

            switch (again)
            {
            case 'y':
            case 'Y':
                cout << "you entered yes" << endl;
                MATCHES = 21;

                playagin = true;
                showSwitch = true;
                continue;

            case 'N':
            case 'n':
                return 0;

            default:
                break;
            }
            continue;
        }
//endf of checking
        cout << endl;
        cout << "Computer removes ";
        Com_turn(MATCHES, Com_remove);
        cout << Com_remove << "." << endl;

        // player turn
        // cout << "Player Turn - Matches:";
        // Print_Macthes(Com_remove, MATCHES);

        cout << endl;

        // cout << "Remove (1 - 3):";
        // cin >> Num_remove;

    } while (cin.fail() || MATCHES > 1);

    return 0;
}