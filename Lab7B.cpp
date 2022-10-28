/*
Name: Jeol Kabura, 2001972424 , 1006, Lab 6b
Description: practice using basic input/output, file input, and two dimensional arrays.
Input: Prompts the user for a filename and reads the filename into a string.
Output: out puts the data in the file including the SUM OF ALL THE NUMBERS.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

const int ROW_COUNT = 12;
const int COlUM_CONT = 2;
int main()
{
    double max = 0;
    double min = 200;
    double sum_min = 0;

    // Create an input stream to read a file
    ifstream fileReader;
    string filename = " ";
    string name = " ";
    double sum_max = 0;
    bool First_Line = true;

    // declaring arrays

    double array2d[ROW_COUNT][COlUM_CONT];
    string First_array[2];
    string sec_line[2];
    // double avrage = arr[0];
    do
    {
        cout << "Enter a file name" << endl
             << "**";
        getline(cin, filename);
        cout << endl;
        fileReader.open(filename);
        while (!fileReader.is_open())
        {
            // if the input is not vaild
            cout << "Error: Invalid file name" << endl;
            fileReader.clear();
            cout << "Enter a file name" << endl
                 << "**";

            getline(cin, filename);
            cout << endl;
            fileReader.open(filename);
        }
        // ask for a name to search

        int cnt = 0;

        while (!fileReader.eof())
        {
            if (First_Line == true)
            {
                fileReader >> First_array[cnt];
                fileReader >> sec_line[cnt];
                First_Line = false;
            }

            for (int i = 0; i < ROW_COUNT; i++)
            {
                for (int j = 0; j < COlUM_CONT; j++)
                {

                    fileReader >> array2d[i][j];
                }
            }
            // line that has a error
            if (fileReader.fail() && !fileReader.eof())
            {
                // error output
                fileReader.clear();
                cout << "Error: Invalid input in file." << endl;

                fileReader.ignore(1000, '\n');
                continue;
            }
            cnt++;
        }

        // outputing the results
        /// finding the sum of all the rows
        for (int i = 0; i < ROW_COUNT; i++)
        {
            for (int j = 0; j < COlUM_CONT; j++)
            {

                cout << array2d[i][1] << " ";
                if (array2d[i][j] > max)
                {
                    max = array2d[i][j];
                }
                if (array2d[i][j] < min)
                {
                    min = array2d[i][j];
                }

                sum_min += array2d[i][0];
                sum_max += array2d[i][1];
                //cout << "this si the array :" << array2d[i][0];
            }
            cout << endl;
        }
        
        for (int i = 0; i < 1; i++)
        {
            cout << First_array[i] << " " << sec_line[i] << endl;
        }
        cout<<fixed<<setprecision(2);
        cout << "Lowest temperature of the year was "<<min/24<<"° F." << endl;
        cout << "Highest temperature of the year was "<<max/24<<"° F." << endl;
        
        cout << "Average low temperature of the year was "<<sum_min/24<<"° F."<< endl;
        cout << "Average high temperature of the year was "<<sum_max/24<<"° F."<< endl;
    } while (cin.fail());
    return 0;
}
