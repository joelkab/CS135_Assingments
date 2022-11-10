#include <iostream>
#include <fstream>
#include <vector>
#include <ctype.h>

using namespace std;

// prototype of function

// read data example
/**
 * @brief This function reads the file and stores the data in a vector
 * idea: read the file line by line, then using for loop to read each character
 *      and store it in a vector (row). After we done with each line/row, we push
 *      the row into the board vector.
 * @param fileName - the name of the file
 * @return vector<vector<char>> - the vector containing the data from the file
 */
vector<vector<char> > readData(string fileName);

// using nested for loops and isAlpha()
/**
 * @brief This function replace all the alphabets in the board with '_'
 * idea: using nested for loops to go through the board, and check if the character
 *     is an alphabet, if it is, replace it with '_' by using isAlpha() function
 * Notes: isAlpha() function is from cctype library. It returns true if the character
 *    is an alphabet, otherwise, it returns false.
 * Notes: 1st for loop is for going through the rows, 2nd for loop is for going through the columns
 * @param v - the vector containing the data from the file
 * @return vector<vector<char>> - return the board with all alphabets replaced with '_'
 */
vector<vector<char> > replace1(vector<vector<char> > v);

// using nested loops and if statements
/**
 * @brief same as replace1() function, but using if statements instead of isAlpha()
 *
 * @param v
 * @return vector<vector<char>>
 */
vector<vector<char> > replace2(vector<vector<char> > v);

// print 2d vector
/**
 * @brief This function prints the 2d vector -> literlly take from textbook (307-310 - Richard L. Halterman book)
 *
 * @param v - the vector containing the data from the file
 */
void print2dVector(vector<vector<char> > v);
// function for guessing
vector<vector<char> > GUESS(vector<vector<char> > &v, char charTo_Find, vector<vector<char> > KEY, int &found, vector<char> &used, bool &is_used);
// getting user input

double getInput(string prompt);

// checking for user error
bool checkFailure(char input);
// game over
bool GamOver(vector<vector<char> > v, vector<vector<char> > KEY);

bool openFile(string promt,vector<vector<char> > &Data,vector<vector<char> > &data2);

int main()
{
//printing the logo
cout<<"     Welcome to\n";
cout<<"         W\n"<<"     C R O S S\n"
<<"         R\n"<<"         D\n";
cout<<endl;
//
    // make 2d vector for data from files
    vector<vector<char> > data1; // use just nested loop and if
    vector<vector<char> > data2; // use nested loop and isAlpha()
    
    // read data from files
    //data1 = readData("level1.txt");

    char guess;
    // vector i will be using
    vector<vector<char> > data2_copy;
    vector<vector<char> > GUS;
    // storing used characters
    vector<char> used_char;
    // variables for the game
    int total_Guess = 5;
    int found = 0;
    string promt = "enter a Letter: ";
    
    bool is_used = false;
    bool valid = false;

    string Intro_promt ="Enter level to play:";
   



while (openFile(Intro_promt,data2,data2_copy) == false)
{
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
    }
  
}
data2 = replace2(data2);
    do
    {
        guess = getInput(promt);

        GUS = GUESS(data2, guess, data2_copy, found, used_char, is_used);
        // checking if char is not found
        if (found == -1)
        {
            cout << "The letter is not on the board \n";
            total_Guess--;
        }
        cout << "remaining incorrect guess: " << total_Guess << endl;

        print2dVector(GUS);
        
        // reset the value found
        cout << found << endl;
        found = -1;

        for (char i : used_char)
        {
            cout << i << ' ';
        }
        if (GamOver(data2, data2_copy) == true)
        {
            return 0;
        }
        cout << endl;

    } while (total_Guess > 0 || is_used == true);
    cout<<"Better luck next time!\n";

    return 0;
}

// using just netsed for loops to read in data
vector<vector<char> > readData(string fileName)
{
    vector<vector<char> > board; // 2d vector to store data

    ifstream file(fileName); // open file

    if (file)
    {
        string line;

        //! checkpoint: read and make sure you understand this part/how it works
        //! don't blindly just copy my code
        while (getline(file, line)) // get line from file
        {
            vector<char> row;                       // we will store each line/row in a vector
            for (int i = 0; i < line.length(); i++) // this will loop through each charatcer in the line
            {
                row.push_back(line[i]); // add each character to the row vector
            }
            board.push_back(row); // add the row vector to the board vector
        }
        //! end of checkpoint if you read it, you will know how to fix the errors in the code
    }
    else
    {
        cout << "File not found\n";
    }
    file.close();
    return board;
}


vector<vector<char> > replace1(vector<vector<char> > v)
{
    for (int i = 0; i < v.size(); i++) // loop rows
    {
        for (int j = 0; j < v[i].size(); j++) // loop cols
        {
            if (isalpha(v[i][j])) // isalpha() is a function that check if the char is a letter
            {
                v[i][j] = '_';
            }
        }
    }

    // return 2d vector
    return v;
}

// using nested loops and if statements
vector<vector<char> > replace2(vector<vector<char> > v)
{
    // we already has data for v -> no need to read again
    // so just need nested loop to replace those char that not ! and - with _
    for (int i = 0; i < v.size(); i++) // loop rows
    {
        for (int j = 0; j < v[i].size(); j++) // loop cols
        {
            //! checkpoint: same with above
            // so if it is letter -> we will replace it with _

            if (isalpha(v[i][j]))
            {
                v[i][j] = '_';
            }

            //! again, the code will need be change little bit to work -> hint: i (row) and j (col)
        }
    }

    // return 2d vector
    return v;
}
vector<vector<char> > GUESS(vector<vector<char> > &v, char charTo_Find, vector<vector<char> > KEY, int &found, vector<char> &used, bool &is_used)
{
    // we already has data for v -> no need to read again
    // so just need nested loop to replace those char that not ! and - with _
    for (int i = 0; i < v.size(); i++) // loop rows
    {

        is_used = false;
        for (int j = 0; j < v[i].size(); j++) // loop cols
        {
            //! checkpoint: same with above

            // so if it is letter -> we will replace it with _
            if (KEY[i][j] == toupper(charTo_Find))
            // turns it to upper case
            {
                // checking if letter is already used.
                if (v[i][j] == KEY[i][j])
                {
                    cout << "letter is already used" << endl;
                    is_used = true;
                    found++;
                    break;
                }
                cout << "found" << endl;
                v[i][j] = KEY[i][j];
                found++;

                used.push_back(v[i][j]);
            }

            //! again, the code will need be change little bit to work -> hint: i (row) and j (col)
        }
    }

    // return 2d vector
    return v;
}

// print 2d vector
void print2dVector(vector<vector<char> > v)
{
    
    for (int i = 0; i < v.size(); i++) // this will loop through each row
    {
        for (int j = 0; j < v[i].size(); j++) // this will loop through each column
        {
            cout << v[i][j];
        }
        cout << endl;
    }
}

bool checkFailure(char input)
{

    if (cin.fail())
    {
        cout << "Error: Invalid radius!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

        // returns false if the input is not valid
        return false;
    }

    // returns true if the input is valid
    return true;
}

// getting user input
double getInput(string prompt)
{
    char input = ' ';
    cout << prompt;
    cin >> input;
    
    cout << endl;
//checking if inout is a number // 0 means it is number 
    while ( isalpha(input) == 0)
    {
        cout<<"error\n";
        cout << prompt << endl;
        cin >> input;
        cout << endl;
        continue;
    }

    return input;
}

// error checking

// winner
bool GamOver(vector<vector<char> > v, vector<vector<char> > KEY)
{

    if (KEY == v)
    {
        cout << "GamOver you win " << endl;
        return true;
    }
    return false;
}
//checking for invalid file.
bool openFile(string promt,vector<vector<char> > &Data,vector<vector<char> > &data2){
int option = 0;
cout<<promt;
cin>>option;

if(option == 1){

    Data = readData("level1.txt");
    data2 = readData("level1.txt");
   
    Data = replace1(Data);
     
    return true;
} else if(option == 2){
    Data = readData("level2.txt");
   data2 = readData("level2.txt");
   
    Data = replace1(Data);
    return true;
} 
else if(option == 3){
    Data = readData("level3.txt");
    data2 = readData("level3.txt");
   
    Data = replace1(Data);
    return true;
} 
else if (option> 2){
    cout<<"Level files could not be found!\n";
    return false;
}
else if (option < 1){
   cout<<"Invalid Entry!\n";
}

return false;

}