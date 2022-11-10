#include <iostream>
#include <string>

using namespace std;

void get_Inputs(string &str_input1)
{

    string str_promt = "Enter a string";

    int min = 1;
    int max = 50;
string input = " ";
    cout << str_promt << endl;
    cin >> input;

  
    str_input1 = input;
}


string operator*(string s, size_t count)
{
    string ret;

    for (size_t i = 0; i < count; ++i)
    {
        ret = ret + s;
    }
    return ret;
}

int main()
{
    int num = 0;

    string str_input1;
    //get_Inputs(str_input1);
    cin >>num;

    string data = "+";
    cout << 10 + 10 << "\n";
}