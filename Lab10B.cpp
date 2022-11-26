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

const int size = 10;
int main()
{
   
    PurchaseType PurType[size];
    ifstream fileReader;
    string prompt = "Enter file name";

    openFile(fileReader, prompt);
    readFile(fileReader, PurType);
    printPurchaseData(PurType,size);
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
        cout << "Error: Invalid file" << endl;
        fileReader.clear();
        cout << "Enter file name" << endl
             << "**";
             cout<<endl;
        getline(cin, filename);
        fileReader.open(filename);
    }
}
void readFile(ifstream &fileReader, PurchaseType purchases[])
{
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

        purchases[cnt].taxRate = stod(line);
        
        cnt++;
    }
    

}
void printPurchaseData(PurchaseType purchases[], int size){
 double total = 0.0;
int unique_cus = 0;
//10 is cnt i would pass by reference cnt but its too much code.

cout<<"+-------------+--------------+-------+----------+----------+--------+\n"
<<"| Customer ID | Product Name | Price | Quantity | Tax Rate | Total  |\n"
<<"+-------------+--------------+-------+----------+----------+--------+\n";
    for (int i = 0; i < 10; i++)
    {
        if (purchases[i].customerID != purchases[i + 1].customerID)
        {
            unique_cus++;
        }

        double totaltax = purchases[i].price * purchases[i].qtyPurchased * (purchases[i].taxRate + 1);
        cout << fixed<<setprecision(2)<<left
            << "|     "<< purchases[i].customerID << " "
             <<"|"<<right<<setfill(' ')<<setw(13)<< purchases[i].productName << " "
             <<"|"<<right<<setfill(' ')<<setw(6)<< purchases[i].price << " "
             << "|        "<< purchases[i].qtyPurchased << " "
             <<"|"<<right<<setfill(' ')<<setw(9)<<purchases[i].taxRate * 100<< " "
             <<"|"<<right<<setfill(' ')<<setw(7)<<totaltax << " |"<<endl;
            

        total += purchases[i].price * purchases[i].qtyPurchased * (purchases[i].taxRate + 1) / 10;
    }
cout <<"+-------------+--------------+-------+----------+----------+--------+\n";


cout << "Unique users:  "<<unique_cus<<endl;
cout << fixed << setprecision(2) << "average total: " << total ;
    
}