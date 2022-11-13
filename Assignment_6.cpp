/*
Name: Joel Kabura, 2001972424 , 1006, AS6
Description: you will create a crossword game that reads the levels from data files. The
    user will select a level to play, and the application will load the level if the data file is available.
    User’s input is to be validated and the game needs to tell the user if the level’s data file is
    missing. The user can have 5 incorrect guesses before losing the game.
Input: input a an integral of a file u want to read, enter chracters
Output: program willout put a error message if the character you enter in not correct or already used 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <ctype.h>

using namespace std;
// prototype of function
vector<vector<char> > readData(string fileName);
vector<vector<char> > replace1(vector<vector<char> > v);
// using nested loops and if statements
vector<vector<char> > replace2(vector<vector<char> > v);
// print 2d vector
void print2dVector(vector<vector<char> > v);
// function for guessing
vector<vector<char> > GUESS(vector<vector<char> > &v, string charTo_Find, vector<vector<char> > KEY, int &found, vector<char> &used, bool &is_used,string &been_used);
// getting user input

string getInput(string prompt,vector<vector<char> > v, string been_used,vector<vector<char> > z);

// checking for user error
// game over
bool GamOver(vector<vector<char> > v, vector<vector<char> > KEY);

bool openFile(string promt,vector<vector<char> > &Data,vector<vector<char> > &data2);
bool BeenUsed (vector<vector<char> > v, string been_used,vector<vector<char> > z);
int Playagin(string yes_no,bool &show);
int startgame(string guess,bool &show);

int main()
{
string guess;
bool show = true;
startgame(guess,show);


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
            for (unsigned int i = 0; i < line.length(); i++) // this will loop through each charatcer in the line
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
    for (unsigned int i = 0; i < v.size(); i++) // loop rows
    {
        for (unsigned int j = 0; j < v[i].size(); j++) // loop cols
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
    for (unsigned int i = 0; i < v.size(); i++) // loop rows
    {
        for (unsigned int j = 0; j < v[i].size(); j++) // loop cols
        {
            //! checkpoint: same with above
            // so if it is letter -> we will replace it with _

            if (isalpha(v[i][j]))
            {
                v[i][j] = '_';
            }
        }
    }
    // return 2d vector
    return v;
}
vector<vector<char> > GUESS(vector<vector<char> > &v, string charTo_Find, vector<vector<char> > KEY, int &found, vector<char> &used, bool &is_used, string &been_used)
{
    for (unsigned int i = 0; i < v.size(); i++) // loop rows
    {

        is_used = false;
        for (unsigned int j = 0; j < v[i].size(); j++) // loop cols
        {
            // so if it is letter -> we will replace it with _
            if (KEY[i][j] == toupper(charTo_Find[0]))
            // turns it to upper case
            {
                // checking if letter is already used.
                if (v[i][j] == KEY[i][j])
                {
                    is_used = true;
                    found++; 
                    return v;
                }
                //cout << "found" << endl;
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
    
    for (unsigned int i = 0; i < v.size(); i++) // this will loop through each row
    {
        for (unsigned int j = 0; j < v[i].size(); j++) // this will loop through each column
        {
            cout << v[i][j];
        }
        cout << endl;
    }
}
// getting user input
string getInput(string prompt,vector<vector<char> > v, string been_used,vector<vector<char> > z)
{
    string input = " ";
    cout << prompt;
    cin >> input;
    
    cout << endl;
//checking if inout is a number // 0 means it is number 
    while ( cin.fail())
    {
        cout<<"error\n";
        cout << prompt << endl;
        cin >> input;
        cout << endl;
    }
    return input;
}
//checking if a letter has been used 
bool BeenUsed (vector<vector<char> > v, string been_used,vector<vector<char> > z){

for (unsigned int i = 0; i < v.size(); i++) // this will loop through each row
    {
        for (unsigned int j = 0; j < v[i].size(); j++) // this will loop through each column
        {
            if(been_used[i]== v[i][j]){
                cout<<"been used\n";
                return false;
            }
        }
       
    }
    return true;
}
// error checking

// winner
bool GamOver(vector<vector<char> > v, vector<vector<char> > KEY)
{

    if (KEY == v)
    {
        
        cout << "\nCongratulations! you solved the level!" << endl;
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
}  if(option == 2){
    Data = readData("level2.txt");
    data2 = readData("level2.txt");
    Data = replace1(Data);
    return true;
} 
if(option == 3){
    Data = readData("level3.txt");
    data2 = readData("level3.txt");
    Data = replace1(Data);
    return true;
} 
 if (option> 2){
    cout<<endl;
    cout<<"Level files could not be found!\n";
    return false;
}
 if (option < 1){
cout<<endl;
   cout<<"Invalid Entry!\n";
}

return false;

}

//play again
int Playagin(string prompt,bool &show){

string guess;
string input = " ";
cout << prompt;
cin >> input;
cout<<endl;
//checking if inout is a number // 0 means it is number 
while ( input != "y" && input != "Y" && input != "n" && input != "N" )
{
    cout<<"Invalid entry!\n";
    cout << prompt;
    cin >> input;
    cout<<endl;
}
    
show = false;
    if(input == "y" || input == "Y") {
        
        startgame(guess,show);
    } else if (input == "n" || input == "N"){
        cout<<"Thank you for playing CrossWord!";
        return 0;
    }
    return 0;

}
//starting the game 
int startgame(string guess,bool &show){

//printing the logo

//
    // make 2d vector for data from files
    vector<vector<char> > data1; // use just nested loop and if
    vector<vector<char> > data2; // use nested loop and isAlpha()
    
    // read data from files
    //data1 = readData("level1.txt");

    // vector i will be using
    vector<vector<char> > data2_copy;
    vector<vector<char> > GUS;
    // storing used characters
    vector<char> used_char;
    // variables for the game
    int total_Guess = 5;
    int found = 0;
    string promt = "Enter a Letter: ";
    
    bool is_used = false;
    

    string Intro_promt ="Enter level to play:";
    string been_used = " ";
 
    string total_used = " ";
    string play_agin = "Play again? (y/n)";
   


if(show == true)
{
cout<<"\n     Welcome to\n\n";
cout<<"         W\n"<<"     C R O S S\n"
<<"         R\n"<<"         D\n";
cout<<endl;

show = false;
}
while (openFile(Intro_promt,data2,data2_copy) == false)
{
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
    }
  
}
cout<<endl;
cout<<endl;

print2dVector(data2);
cout<<endl;

data2 = replace2(data2);
    do
    {
        guess = getInput(promt,data2,been_used, data2_copy);
        GUS = GUESS(data2, guess, data2_copy, found, used_char, is_used,been_used);

        if(is_used == true){
            cout<<"The letter is already guessed, try again!\n";
        }

        for(unsigned int i =0; i < been_used.size(); i++){

    if(guess[0] == been_used[i]){
        cout<<"The letter is already guessed, try again!\n";
        found++;
    }
}
        is_used = false;
        
        // checking if char is not found
        if (found == 0)
        {
             been_used += guess[0];

            cout << "The letter is not on the board \n";
            
            total_Guess--;
        }
       
        cout << "Remaining incorrect guesses: " << total_Guess << endl;
        cout<<endl;

        print2dVector(GUS);
        
        // reset the value found
        found = 0;
   
        if (GamOver(data2, data2_copy) == true)
        {
            Playagin(play_agin,show);
            return 0;
        }
        cout << endl;

    } while (total_Guess > 0 || is_used == true);
    cout<<"Better luck next time!\n";
    Playagin(play_agin,show);

return 0;
}
//work on checking if a character has been used.