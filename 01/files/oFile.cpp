#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream oFile("sampleFile.txt", ios :: trunc);
    
    oFile << "Inserted this text into sampleFile.txt";

    oFile.close();
}