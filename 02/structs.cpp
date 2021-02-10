#include <iostream>
#include <string>

using namespace std;

// Definition of the structure
struct student
{
    string name;
    string email;
    int birthyear;
    string address;
};

int main() {

    // Initialization: Method I (Need to remember correct order of members)
    // student stu = {"ABC", "abc@colorado.edu", 1987, "Boulder"};

    // Initialization: Method II (Access members using dot operator)
    student stu ; //student defined
    stu.address = "Boulder, CO";
    stu.email = "abc@colorado.edu";
    stu.birthyear = 1987;
    stu.name = "ABC";

    cout << stu.name << endl << stu.email << endl << stu.birthyear << endl << stu.address << endl;

    cout << "\nPointer-to-struct\n--------------------\n";

    // Accessing members using pointer-to-struct
    student *stu1;
    stu1 = &stu;
    stu1->name = "XYZ";  //Need to use -> operator to access data members via pointer-to-struct

    cout << stu1->name << endl;
    cout << stu1->email << endl;
    cout << stu1->birthyear << endl;
    cout << stu1->address << endl;

    return 0;
}