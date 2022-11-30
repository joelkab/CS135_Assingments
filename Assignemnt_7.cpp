#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <ctype.h>
#include <stdio.h>
using namespace std;
const string USER = "meowmin";
const string PASS = "1w@ntch1cken";
const string COMMAND_PROMPT = ">";
const string COMMAND_DELIMITER = " ";
const string QUIT_CMD = "quit";
const string SHOW_CMD = "show";
const string CREATE_CMD = "create";
const string DELETE_CMD = "delete";
const string TABLE_FILETYPE = ".csv";
const string TABLE_FILE_DIRECTORY = "data/";
const string TABLES_TABLE = "data/tables.csv";
const string SHOW_ARG_1 = "tables";
const string USAGE_MSG = "Usage: ./a.out <username> <password>\n";
const string WELCOME_MSG = "Welcome ";
const string VALID_ARG_MSG = "";
const string QUIT_ARG_CNT_MSG = "QUIT Error: invalid argument count";
const string SHOW_ARG_CNT_MSG = "SHOW Error: invalid argument count";
const string CREATE_ARG_CNT_MSG = "CREATE Error: invalid argument count";
const string DELETE_ARG_CNT_MSG = "DELETE Error: invalid argument count";
const string TABLE_CREATE_SUCCESS_MSG = " table created successfully";
const string TABLE_DELETE_SUCCESS_MSG = " table removed successfully";
const string INVALID_CREDENTIALS_MSG = "Error: invalid credentials\n";
const string INV_CMD_MSG = "Error: invalid command name";
const string SHOW_INV_OPT_MSG = "SHOW Error: invalid option";
const string CREATE_INV_TABLE_NAME_MSG = "CREATE Error: table name should only contain "
                                         " alpha numeric characters, '-', or '_'";
const string CREATE_EXISTS_MSG = "CREATE Error: table already exists";
const string CREATE_INV_HEADERS_MSG = "CREATE Error: column names should be  separated "
                                      " by delimiter and should only contain alpha numeric characters, '-', or '_'";
const string DELETE_UNDELETABLE_MSG = "DELETE Error: table cannot be deleted";
const string DELETE_INV_TABLE_NAME_MSG = "DELETE Error: invalid table name";
void header();
string toLower(string);
void getCredentials(int argc, char const *argv[], string &user, string &pass);
bool validateCredentials(string, string);
// creating commandloop
void commandLoop();
// Getting input
vector<string> getInput();
string validateArguments(vector<string> args);
void executeCommand(vector<string> args);
int removeDupWord(string str);
int countWords(string str);

// sections 2/3 add function prototypes
// YOUR CODE HERE
int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        cout << USAGE_MSG;
        return 0;
    }
    string user = "", pass = "";
    getCredentials(argc, argv, user, pass);

    if (validateCredentials(user, pass) == true)
    {

        // 1.2 call get header
        // YOUR CODE HERE
        header();

        // 2.1 call the loop to get commands from the user
        // YOUR CODE HERE
        commandLoop();
    }
    return 0;
}
// used for section 1
// prints header
void header()
{
    cout << "+---------------------------------------------------------------------+\n"
         << "|   __   __  _______  _______  _     _    _______  _______  ___        | \n "
         << "|  |  |_|  ||       ||       || | _ | |  |       ||       ||   |       | \n "
         << "|  |       ||    ___||   _   || || || |  |  _____||   _   ||   |       | \n "
         << "|  |       ||   |___ |  | |  ||       |  | |_____ |  | |  ||   |       | \n "
         << "|  |       ||    ___||  |_|  ||       |  |_____  ||  |_|  ||   | _ __   | \n "
         << "|  | ||_|| ||   |___ |       ||   _   |   _____| ||      | |         |   |\n "
         << "|  |_|   |_||_______||_______||__| |__|  |_______||____||_|| _______ | | \n "
         << "|                                                                    v1 .0.0 | \n "
         << " + -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -+\n ";
}
// Used for section 2
// lowercases string and returns it
string toLower(string s)
{
    for (char &x : s)
        x = static_cast<char>(tolower(x));
    return s;
}
// Used for section 3
// Prints the csv at the passed file path
bool printTable(string file)
{
    string current = "", rest = "", delimiter = ",";
    int rowCnt = 0;
    ifstream toShow(file);
    getline(toShow, current);
    int colCnt = count(current.begin(), current.end(), delimiter[0]) + 1;
    toShow.seekg(0);
    vector<unsigned int> widths(colCnt, 0);
    while (getline(toShow, rest))
    {
        for (int i = 0; i < colCnt; i++)
        {
            current = rest.substr(0, rest.find(delimiter));
            rest = rest.erase(0, rest.find(delimiter) + 1);
            if (current.size() > widths[i])
                widths[i] = current.size();
        }
        rowCnt++;
    }
    if (rowCnt > 1)
    {
        toShow.clear();
        toShow.seekg(0);
        cout << file.substr(file.find("data/") + 5, file.length() - 9) << "table : \n ";
        cout
            << setfill('-')
            << right;
        for (int i = 0; i < colCnt; i++)
            cout << "+" << setw(widths[i] + 3);
        cout << "+" << endl;
        getline(toShow, current);
        vector<string> ret;
        string token = "";
        while (current.find(delimiter) != string::npos)
        {
            token = current.substr(0, current.find(delimiter));
            current = current.erase(0, current.find(delimiter) +
                                           delimiter.length());
            ret.push_back(token);
        }
        ret.push_back(current);
        cout << setfill(' ') << left;
        for (unsigned int i = 0; i < widths.size(); i++)
            cout << "| " << setw(widths[i]) << ret[i] << " ";
        cout << "|" << endl;
        cout << setfill('-') << right;
        for (int i = 0; i < colCnt; i++)
            cout << "+" << setw(widths[i] + 3);
        cout << "+" << endl;
        while (getline(toShow, current))
        {
            ret.clear();
            while (current.find(delimiter) != string::npos)
            {
                token = current.substr(0, current.find(delimiter));
                current = current.erase(0, current.find(delimiter) +
                                               delimiter.length());
                ret.push_back(token);
            }
            ret.push_back(current);
            cout << setfill(' ') << left;
            for (unsigned int i = 0; i < widths.size(); i++)
                cout << "| " << setw(widths[i]) << ret[i] << " ";
            cout << "|" << endl;
        }
        cout << setfill('-') << right;
        for (int i = 0; i < colCnt; i++)
            cout << "+" << setw(widths[i] + 3);
        cout << "+" << endl;
        cout << rowCnt - 1 << " row(s) in set.\n";
        return true;
    }
    return false;
}

// Fill this function out for section 1.1
void getCredentials(int argc, char const *argv[], string &user, string &pass)
{

    user = argv[1];
    pass = argv[2];

    for (int i = 0; i < argc; ++i)
    {
        cout << argv[i] << "\n";
    }
    // 1.1 get username and password from cmd args
    // YOUR CODE HERE
}
// Fill this function out for section 1.2
bool validateCredentials(string u, string p)
{
    // 1.2 make sure proper user/pass
    // YOUR CODE HERE

    if (u == USER && p == PASS)
    {

        cout << WELCOME_MSG << " " << u << endl;
        return true;
    }
    else
    {
        cout << INVALID_CREDENTIALS_MSG;
        return false;
    }
}

// 2.1 add getInput() function
vector<string> getInput()
{

    vector<string> Vec_Getinputs;

    string input = " ";

    string token;

    cout << COMMAND_PROMPT;
    getline(cin, input);
    istringstream ss(input);
    while (getline(ss, token, ' '))
    {
        Vec_Getinputs.push_back(token);
    }
    return Vec_Getinputs;
}

// 2.1 add validateArguments(vector<string>) function
string validateArguments(vector<string> args)
{
    string input = " ";

    for (int i = 0; i < args.size(); i++)
    {
        cout << i <<args[i] << endl;

        input += args[i];

        // checking to see it quite is typed in
        if (args[i] == QUIT_CMD)
        {
            exit(0);
        }

        if (args[i] == CREATE_CMD && (args.size() < 3 || args.size() > 3))
        {
            cout << "ewowoowowowow\n";
            cin.clear();
        }
        
    }
    return input;
}
// 2.1 add executeCommand(vector<string>) function
void executeCommand(vector<string> args)
{
}
// 2.1 add commandLoop() function
void commandLoop()
{

    vector<string> input;
    while (bool statues = true)
    {

        input = getInput();
        string valid = validateArguments(input);
        executeCommand(input);
        if (valid == QUIT_CMD)
        {
            statues = false;
        }
    }
}
int countWords(string str)
{
    // Breaking input into word
    // using string stream

    // Used for breaking words
    stringstream s(str);

    // To store individual words
    string word;

    int count = 0;
    while (s >> word)
        count++;
    return count;
}

/*
DO NOT REMOVE
Copyright 2022 Alex St. Aubin. All Rights Reserved.
Unauthorized reproductions of this handout and any accompanying code
are strictly forbidden under Nevada State and US Federal law.
*/