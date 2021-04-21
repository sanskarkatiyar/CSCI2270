#include <iostream>
#include <string>
#include <fstream>

#include <map>

using namespace std;

int main(int argc, char** argv)
{
    map<int, string> H;    // map<key_type, value_type>
    int key_to_search = 121;
    int key_to_remove = 121;

    // Let's insert a bunch of records
    ifstream fp("Data.csv");
    for (int i = 0; i < 21 && fp; i++) {
        // extract the data from the line
        string temp;
        int key; string value;
        getline(fp, value, ',');
        getline(fp, temp);
        key = stoi(temp);

        // insert the record into H
        H[key] = value;
    }
    fp.close();


    // Search for a particular value
    cout << "SEARCHING: ";
    if (H.find(key_to_search) == H.end()) {
        // condition for not found
        cout << ("Key " + to_string(key_to_search) + " does not exist.") << endl;
    }
    else {
        cout << ("Key " + to_string(key_to_search) + ": " + H[key_to_search]) << endl;
    }


    // Delete a particular record: Ensure it exists first
    if (H.find(key_to_remove) == H.end()) {
        cout << ("Key " + to_string(key_to_remove) + " does not exist.") << endl;
    }
    else {
        cout << endl << ("DELETING: " + to_string(key_to_remove)) << endl;
        H.erase(key_to_remove);
    }


    // Iterate through the table

    for (map<int, string>::const_iterator it = H.begin(); it != H.end(); it++) {
        cout << it->first << " -> " << it->second << endl;
    }

    return 0;
}