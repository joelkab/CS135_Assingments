#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <cctype>
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
string validateArguments(vector<string> args, bool &succes);
void executeCommand(vector<string> args);
int removeDupWord(string str);
bool is_only_alpha(const string &str);
bool is_file_exist(string fileName);
void DeleteLine(string filename);

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
    Vec_Getinputs.clear();

    string input = " ";

    string token;
    cout << endl;
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
string validateArguments(vector<string> args, bool &succes)
{
    string input = " ";
    //
    string filename = " ";
    string input2 = " ";

    for (int i = 0; i < args.size(); i++)
    {
        input += args[i];
        input2 += args[i + 1];
    }

    for (int i = 0; i < args.size(); i++)
    {

        input2 += args[i + 1];
        // QUIT
        //  checking to see it quite is typed in
        if (args[i] == QUIT_CMD)
        {
            exit(0);
        }

        // checking to see if Delete is typed n [
        if (args[i] == DELETE_CMD && (args.size() < 2 || args.size() > 2))
        {
            cout << DELETE_ARG_CNT_MSG << endl;
            cin.clear();
        }
        // DELETE
        if (args[i] == DELETE_CMD && args.size() == 2)
        {
            cout << "you entered delete\n";
            if (args[1] == SHOW_ARG_1)
            {
                cout << DELETE_UNDELETABLE_MSG << endl;
                return input;
            }
            // checking to see if the file already exists
            if (is_file_exist(args[1]) == true)
            {
                return VALID_ARG_MSG;
            }
            else
            {
                cout << DELETE_INV_TABLE_NAME_MSG << endl;
                return input;
            }
        }

        //  checking to see if Show if typed in
        if (args[i] == SHOW_CMD && (args.size() < 1 || args.size() > 1))
        {
            cout << SHOW_ARG_CNT_MSG << endl;
            cin.clear();
        }
        // SHOW
        if (args[i] == SHOW_CMD && args.size() == 1)
        {
            cout << "you entered show\n";
            return VALID_ARG_MSG;
        }
        // checking if there are 3 argmemtns
        if (args[i] == CREATE_CMD && (args.size() < 3 || args.size() > 3))
        {
            cout << CREATE_ARG_CNT_MSG << endl;
            cin.clear();
        }

        // CREATE
        if (args[i] == CREATE_CMD && args.size() == 3)
        {
            cout << "welcome u have 3 arguments \n";
            if (is_only_alpha(input) == false)
            {
                cout << CREATE_INV_HEADERS_MSG << endl;
                return input;
            }
            // we know its a alphanumeric character

            // check if the file already exist
            filename = args[1];

            if (is_file_exist(filename) == true)
            {
                return input;
            }

            for (int i = 0; i < input2.size(); ++i)
            {
                // checking if the file colums starts with comma
                if (input2[1] == ',')
                {
                    cout << "can not start with a comma\n";
                    cout << CREATE_INV_TABLE_NAME_MSG;
                    break;
                }
                // checking if the file has 2 commas together
                if (input2[i] == ',' && input2[i + 1] == ',')
                {
                    cout << "there are two comamas in a row\n";
                    cout << CREATE_INV_TABLE_NAME_MSG;
                    break;
                }
                // every thing is valid
                cout << "\nvalid\n";
                succes = true;
                return VALID_ARG_MSG;
            }
        }
    }

    cout << input << endl;
    return input;
}
// 2.1 add executeCommand(vector<string>) function
void executeCommand(vector<string> args)
{

    // CREATE
    if (args[0] == CREATE_CMD)
    {
        ofstream oFile; // output file
        ifstream iFile; // input file
        string filename = args[1];

        oFile.open(filename + TABLE_FILETYPE);
        if (!oFile.is_open())
        {
            cout << "Error opening output file!\n";
        }
        oFile << args[2];
        oFile.close();

        oFile.open("tables.csv", ios_base::app);

        oFile << filename << endl;
        oFile.close();
        cout << "table " << filename << TABLE_CREATE_SUCCESS_MSG << endl;
        
    }
    // SHOW
    if (args[0] == SHOW_CMD)
    {
        cout << "table printed\n";
        printTable("tables.csv");
    }
    // DELETE
    if (args[0] == DELETE_CMD)
    {
        cout << "\nYour in delete\n";
        string deleteline = args[1];
        string filename = "tables.csv";
        DeleteLine("tables.csv");

        // DeleteLine(filename, deleteline, args);

        // delete the file name inside tables table

        // delete the file your tring the delete
    }
}
// 2.1 add commandLoop() function
void commandLoop()
{

    vector<string> input;
    bool sucess = false;



    while (bool statues = true)
    {

        input = getInput();
        string valid = validateArguments(input, sucess);

        if (valid == QUIT_CMD)
        {
            statues = false;
        }
        if (sucess == true)
        {
            executeCommand(input);
        }
        if (valid == VALID_ARG_MSG)
        {
            executeCommand(input);
        }
    }
}
// checking if the file is alph
bool is_only_alpha(const string &str)
{

    for (int i = 1; i < str.size(); ++i)
    {
        if (!isalnum(str[i]) && str[i] != ',' && str[i] != '_' && str[i] != '-')
        {

            cout << str[i] << endl;
            cout << "noooooooooo " << i << endl;

            return false;
        }
    }
    return true;
}
// checking if the file already exits
bool is_file_exist(string fileName)
{
    ifstream myfile;

    myfile.open(fileName + TABLE_FILETYPE);
    if (myfile)
    {
        cout << "file already exists\n";
        return true;
    }
    else
    {
        cout << "file doesn't exist\n";
        return false;
    }
}

void DeleteLine(string filename)
{

    int line_number;

    // Prompt the user to enter the line number to delete in the file, store it
    // into line_number

    // fstream object will be used to read all of the existing lines in the file
    fstream read_file;

    // Open the file with the provided filename
    read_file.open(filename);

    // If file failed to open, exit with an error message and error exit status
    if (read_file.fail())
    {
        cout << "Error opening file." << endl;
    }

    vector<string> lines;
    string line;

    // Read each line of the file and store it as the next element of the vector,
    // the loop will stop when there are no more lines to read
    while (getline(read_file, line))
        lines.push_back(line);

    // Close our access to the file since we are done reading with it
    read_file.close();
    for (int i = 0; i < lines.size(); i++)
    {
        cout << lines[i] << endl;
    }

    ofstream write_file;

    // Open the file with the provided filename
    write_file.open("copytable.csv");

    // If the file failed to open, exit with an error message and exit status
    if (write_file.fail())
    {
        cout << "Error opening file." << endl;
    }

    line_number--;

    // Loop through the vector elements to write each line back to the file
    // EXCEPT the line we want to delete.
    for (int i = 0; i < lines.size(); i++)
        if (lines[i] != "table")
            write_file << lines[i] << endl;

    // Close our access to the file since we are done working with it
    write_file.close();
}

/*
DO NOT REMOVE
Copyright 2022 Alex St. Aubin. All Rights Reserved.
Unauthorized reproductions of this handout and any accompanying code
are strictly forbidden under Nevada State and US Federal law.
*/