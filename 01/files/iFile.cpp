#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char str[10]; // (or) string str;

    ifstream iFile("sampleFile.txt");
    iFile >> str;

    cout << str << "\n";

    cin.get();

    iFile.close();
}