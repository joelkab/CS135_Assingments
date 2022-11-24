/*
Name: Joel Kabura, 2001972424 #, 1006, LAB10A
Description: practice using basic input/output, creating a C++ struct, passing a struct to a
     function, saving data to andreading from a struct.
Input: Prompts the user to enter a thier first name, lastname and grade.
Output:  displasys the student first name, lastname and grade inlcuding the character grade.
*/
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

struct PurchaseType
{

    string customerID;
    string productName;
    double price;
    int qtyPurchased;
    double taxRate;
};

void openFile(ifstream &, string);
void readFile(ifstream &, PurchaseType[]);
void printPurchaseData(PurchaseType[], int);

int main()
{
    int size = 10;
    PurchaseType PurType[size];
    ifstream fileReader;
    string prompt = "Enter file name";

    openFile(fileReader, prompt);
    readFile(fileReader, PurType);
}

void openFile(ifstream &fileReader, string prompt)
{
    string filename = " ";
    cout << prompt << endl
         << "**";
    getline(cin, filename);
    cout << endl;

    fileReader.open(filename);
    while (!fileReader.is_open())
    {
        cout << "Error: Invalid file name" << endl;
        fileReader.clear();
        cout << "Enter file name" << endl
             << "**";
        getline(cin, filename);
        fileReader.open(filename);
    }
}
void readFile(ifstream &fileReader, PurchaseType purchases[])
{
    int size = 10;
    int comma_location = 0;
    string line = "";
    int cnt = 0;

    while (getline(fileReader, line))
    {
        comma_location = line.find(',');
        purchases[cnt].customerID = line.substr(0, comma_location);
        line = line.substr(comma_location + 1, line.length());

        comma_location = line.find(',');
       purchases[cnt].productName = line.substr(0, comma_location);
        line = line.substr(comma_location + 1, line.length());

        comma_location = line.find(',');
        purchases[cnt].price = stod(line.substr(0, comma_location));
        line = line.substr(comma_location + 1, line.length());

        comma_location = line.find(',');
        purchases[cnt].qtyPurchased = stoi(line.substr(0, comma_location));
        line = line.substr(comma_location + 1, line.length());

        comma_location = line.find(',');
        purchases[cnt].taxRate = stod(line.substr(0, comma_location));
        line = line.substr(comma_location + 1, line.length());
        cnt++;
    }

    for (int i = 0; i < cnt; i++)
    {
        cout << left
             << setw(2) << purchases[i].customerID << " "
             << setw(2) << purchases[i].productName << " "
             << setw(2) << purchases[i].price << " "
             << setw(2) << purchases[i].qtyPurchased << " "
             << purchases[i].taxRate << endl;
    }
}
