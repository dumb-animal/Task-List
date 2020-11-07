#include <iostream>
#include <string>

using namespace std;

string ReadLine()
{
    string s;
    getline(cin, s);
    return s;
}

int ReadNumber()
{
    int n;
    cin >> n;
    ReadLine();
    return n;
}