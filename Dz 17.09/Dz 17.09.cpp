// Dz 17.09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "MyString.h"   
using namespace std;

int main()
{
    MyString String("Hello", 80); 
    String.Print();  
    MyString String2(String);
    cout << "#1 Str copy: " << endl;
    String2.Print();  
    cout << "#2 Find str: " << endl;   
    bool found = String2.MysturStr("world");
    if (found) {
        cout << "Substring found!" << std::endl;
    }
    else {
        cout << "Substring not found." << std::endl;
    }
    
    int rez = String.MyChr('w');  
    if (rez != -1) {
        cout << "#3 There is such a symbol: " << rez << endl;  
    }
    else {
        cout << "#3 There is no such symbol " << endl; 
    }
    int SizeStr = String2.MyStrLen();
    if (SizeStr != 0) {
        cout << "#4 String size: " << SizeStr << endl; 
    }
    else {
        cout << "#4 String is empty" << endl;  
    }
    MyString b("World");      
    String2.MyDelCat(b);
    cout << "#5 ";
    String2.Print();    
    String2.MyDelCht('o');
    String2.Print();    
    MyString a("Hello");   
    int index = a.MyStrCmp(b);      
    if (index == 0) {
        cout << "#5 Strings are equal\n";
    }
    if (index == 1) {
        cout << "#5 The first one is bigger than the second one\n";    
    }
    if (index == -1) {
        cout << "#5 First line is less than second\n"; 
    } 
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
