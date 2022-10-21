/*
Name: Jeol Kabura, 2001972424 , 1006, Assignment #5b
Description:ractice using C++ loops, basic input/output, file input, and correcting the input stream
	if it goes to the failstate
Input: Prompts the user for a filename and reads the filename into a string.
Output: print the two numbers, add them and display all the numbers added.
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
	string filename = "";
	int cnt = 0,sum=0, violations = 0;
	string headers = "", line = "", Lic_plate[10000], date[10000], Time[10000];
	int comma_location = 0, Speed[10000], Weight[10000];


	do
	{
		cout << "Open File: " << endl
             << "**";
        getline(cin, filename);
        
        fileReader.open(filename);
        while (!fileReader.is_open())
        {
            cout << "Could not open nonexistant" << endl;
            fileReader.clear();
            cout << "Open File: ";

            getline(cin, filename);
            cout << endl;
            fileReader.open(filename);
        }
		


		// Print the contents of the file to the screen
		while (getline(fileReader, line))
		{
			comma_location = line.find(',');
			Lic_plate[cnt] = line.substr(0, comma_location);
			line = line.substr(comma_location + 1, line.length());

			comma_location = line.find(',');
			date[cnt] = line.substr(0, comma_location);
			line = line.substr(comma_location + 1, line.length());

			comma_location = line.find(',');
			Time[cnt] = line.substr(0, comma_location);
			line = line.substr(comma_location + 1, line.length());

			comma_location = line.find(',');
			Weight[cnt] = stoi(line.substr(0, comma_location));
			line = line.substr(comma_location + 1, line.length());

			Speed[cnt] = stoi(line);

			cnt++;
		}
fileReader.close();
//opening uping the file we want to write to
ofile.open("Report.txt");

		for (int i = 0; i < cnt; i++)
		{

			//cout << "plate: " << Lic_plate[i] << " Date:" << date[i] << " Time" << Time[i]
				// << " weight:" << Weight[i] << " speed:" << Speed[i] << endl;
	//sum += Weight[i] + Speed[i];

	if(Weight[i] > 5000 && Speed[i] > 30 || Weight[i]< 5000 && Speed[i] >45){
		violations++;
		
		ofile << "["<<Time[i]<<"]"<<" "<< Lic_plate[i]<<endl;;
	}
			
		}

		
		cout<<violations<<" violations logged.";




		// Stream must be closed before opening another file with it


	} while (cin.fail());

		return 0;
}