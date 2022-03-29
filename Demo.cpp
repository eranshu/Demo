// Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Demo {
public:
    char* CallingName = {};

    Demo()
    {
        std::cout << "Default Constructor" << endl;
    }

    Demo(const char* name)
    {
        cout << "Constructor " << endl;
        int length = strlen(name) + 1;
        cout << "length of name is " << strlen(name)<<endl;
        //delete[] CallingName;
        CallingName = new char[length];
        strcpy_s(CallingName,length, name);
        cout << "Copied Name is (using strcpy) " << CallingName<<endl;
        for (int i = 0;  i < length; i++)
        {
            char val = name[i];
            CallingName[i] = val;
        }
        cout << "Copied Name is " << CallingName << endl;
    }

    Demo(const Demo& ObjectToBeCopied)
    {
        cout << "Copy Constructor " << endl;
        int length = strlen(ObjectToBeCopied.CallingName) + 1;
        delete[] CallingName;
        CallingName = new char[length];
        strcpy_s(CallingName, length, ObjectToBeCopied.CallingName);
        cout << "Copied Name is " << CallingName << endl;
    }

    Demo operator=(const Demo& ObjectForCopy)
    {
        if (this == &ObjectForCopy)
        {
            cout << "Not Copying Same Object" << endl;
            return *this;
        }
        cout << "Copy assignment Constructor " << endl;
        int length = strlen(ObjectForCopy.CallingName) + 1;
        delete[] CallingName;
        CallingName = new char[length];
        strcpy_s(CallingName, length, ObjectForCopy.CallingName);
        cout << "Copied Name is " << CallingName<<endl;

        return *this;
    }
};

int main()
{
    const char *name = "Anshu Pandey";
    const char* name2 = "Anshu Pandey2";
    Demo obj(name);
    Demo obj2 = obj;
    Demo obj3(name2);
    Demo obj4;
    obj4 = obj3 = obj2;

    //std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
