/*
Name: Jeol Kabura, 2001972424 , 1006, Assignment #5
Description: The program should allow the user to specify the name of the log file
    to analyze.  If the specified file does not open, the user must 
    provide another file name.
    After the file is fully analyzed, the program should report to the 
    terminal the number of violations that it found and recorded.
Input: Prompts the user for a filename.
Output: prints the vehecial that got a violation,licence plate number and time and speed they were going. (just tired:()
*/

// Preprocessor Directives

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
int main()
{
    // string Lic_plate, Date, Time,Weight,Speed;

    // Create an input stream to read a file
    ifstream fileReader;
    ofstream ofile;
    // Ask the user for a file to open
    string filename = "", date_1 = "10-09-2022", date_2 = "10-10-2022", date_3 = "10-11-2022";

    int cnt = 0, violations = 0;
    string headers = "", line = "";

    vector<string> Lic_plate;
    vector<string> date;
    vector<string> Time;

    int comma_location = 0;

    vector<int> Speed;
    vector<int> Weight;
    vector<string> allvio;
    string out_filenames = " ";

    do
    {
        cout << "Open File: ";
        getline(cin, filename);

        fileReader.open(filename);
        while (!fileReader.is_open())
        {
            cout << "Could not open "<<filename << endl;
            fileReader.clear();
            cout << "Open File: ";

            getline(cin, filename);
            fileReader.open(filename);
        }

        // Print the contents of the file to the screen
        while (getline(fileReader, line))
        {
            comma_location = line.find(',');
            Lic_plate.push_back(line.substr(0, comma_location));
            line = line.substr(comma_location + 1, line.length());

            comma_location = line.find(',');
            date.push_back(line.substr(0, comma_location));
            line = line.substr(comma_location + 1, line.length());

            comma_location = line.find(',');
            Time.push_back(line.substr(0, comma_location));
            line = line.substr(comma_location + 1, line.length());

            comma_location = line.find(',');
            Weight.push_back(stoi(line.substr(0, comma_location)));
            line = line.substr(comma_location + 1, line.length());

            Speed.push_back(stoi(line));

            cnt++;
        }

        // opening uping the file we want to write to
 ofile.open("[10-09-2022] Report.txt");
        for (int i = 0; i < cnt; i++)
        {
            
            if ((Weight[i] > 5000 && Speed[i] > 30) || (Weight[i] < 5000 && Speed[i] > 45))
            {
                violations++;
                
                    if (date[i] == date_1)
                    {
                       
                        ofile  << "[" << Time[i] << "]"
                              << " " << Lic_plate[i] << endl;
                    }
                    
                    
                
            }
        }
ofile.close();
ofile.open("[10-10-2022] Report.txt");
        for (int i = 0; i < cnt; i++)
        {
            // cout << "plate: " << Lic_plate[i] << " Date:" << date[i] << " Time" << Time[i]
            //  << " weight:" << Weight[i] << " speed:" << Speed[i] << endl;
            // sum += Weight[i] + Speed[i];
            if ((Weight[i] > 5000 && Speed[i] > 30) || (Weight[i] < 5000 && Speed[i] > 45))
            {
                
                    if (date[i] == date_2)
                    {
                       
                        ofile << "[" << Time[i] << "]"
                              << " " << Lic_plate[i] << endl;
                    }
                    
                    
                
            }
        }
ofile.close();

ofile.open("[10-11-2022] Report.txt");
        for (int i = 0; i < cnt; i++)
        {
            // cout << "plate: " << Lic_plate[i] << " Date:" << date[i] << " Time" << Time[i]
            //  << " weight:" << Weight[i] << " speed:" << Speed[i] << endl;
            // sum += Weight[i] + Speed[i];
            if ((Weight[i] > 5000 && Speed[i] > 30) || (Weight[i] < 5000 && Speed[i] > 45))
            {
                
                    if (date[i] == date_3)
                    {
                       
                        ofile << "[" << Time[i] << "]"
                              << " " << Lic_plate[i] << endl;
                    }
                    
                    
                
            }
        }
ofile.close();

        cout << violations << " violations logged.";
        cout<<endl;


        // Stream must be closed before opening another file with it

    } while (cin.fail());

    return 0;
}