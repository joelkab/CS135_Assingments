/*
Name: Jeol Kabura, 2001972424 , 1006, Lab 6b
Description:  practice file i/o, reading data into 2D arrays, and processing data contained within 2D arrays.
Input: Prompts the user for a filename and reads the filename into a 2darray.
Output: out puts the Max,min,ave min and ave max.
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
    double sum_max = 0;
    // Create an input stream to read a file
    ifstream fileReader;
    string filename = " ";
    string name = " ";

    bool First_Line = true;

    // declaring arrays

    double array2d[ROW_COUNT][COlUM_CONT];
    string First_array[2];
    string sec_line[2];
    // double avrage = arr[0];
    do
    {
        cout << "Enter file name" << endl
             << "**";
        getline(cin, filename);
        cout << endl;
        fileReader.open(filename);
        while (!fileReader.is_open())
        {
            // if the input is not vaild
            cout << "Error: Invalid file name" << endl;
            fileReader.clear();
            cout << "Enter file name" << endl
                 << "**";

            getline(cin, filename);
            cout << endl;
            fileReader.open(filename);
        }
        // ask for a name to search

        int cnt = 0;

        while (!fileReader.eof())
        {
            // reading the firstline of the file
            if (First_Line == true)
            {
                // getting the data
                fileReader >> First_array[cnt];
                fileReader >> sec_line[cnt];
                First_Line = false;
            }

            for (int i = 0; i < ROW_COUNT; i++)
            {
                for (int j = 0; j < COlUM_CONT; j++)
                {
                    // reading the rest of the file.
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
        // outer loop
        for (int i = 0; i < ROW_COUNT; i++)
        {
            // inner loop
            for (int j = 0; j < COlUM_CONT; j++)
            {

                // cout << array2d[i][1] << " ";
                if (array2d[i][j] > max)
                {
                    // max
                    max = array2d[i][j];
                }
                if (array2d[i][j] < min)
                {

                    // min
                    min = array2d[i][j];
                }

                
                // cout << "this si the array :" << array2d[i][0];
            }
            sum_min += array2d[i][0];
            sum_max += array2d[i][1];
        }
        // prints the city and the year
        for (int i = 0; i < 1; i++)
        {
            cout << First_array[i] << " " << sec_line[i] << endl;
        }
        cout << fixed << setprecision(2);
        // prints the highest and coldest temps
        cout << "Lowest temperature of the year was " << min << "° F." << endl;
        cout << "Highest temperature of the year was " << max << "° F." << endl;
        // prints the averages
        cout << "Average low temperature of the year was " << sum_min / 12 << "° F." << endl;
        cout << "Average high temperature of the year was " << sum_max / 12 << "° F." << endl;
    } while (cin.fail());
    return 0;
}
