// Dz 17.09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyString.h"   
using namespace std;
MyString operator+(const MyString& Str1, char c) {
    int length = strlen(Str1.GetString());
    char* newStr = new char[length + 2]; 

    strcpy_s(newStr, length + 2, Str1.GetString());

    newStr[length] = c;
    newStr[length + 1] = '\0';

    MyString result(newStr);
    delete[] newStr;

    return result;  
}
MyString operator+(char c, const MyString& Str1) {  
    int length = strlen(Str1.GetString());
    char* newStr = new char[length + 2];

    strcpy_s(newStr, length + 2, Str1.GetString());

    for (int i = 0; i < length; i++) 
    {
        newStr[i+1] = Str1.GetString()[i];   
    }
    newStr[0] = c;
    newStr[length + 1] = '\0';

    MyString result(newStr);
    delete[] newStr;

    return result;  
}
MyString operator+(const MyString& Str1, int number)
{
    const char* original = Str1.GetString();
    int originalLength = strlen(original);
    int newLength = originalLength + number;
    char* result = new char[newLength + 1]; 

    for (int i = 0; i < originalLength; i++)
    {
        result[i] = original[i];
    }

    for (int i = originalLength; i < newLength; i++)
    {
        result[i] = 'A' + (rand() % 26);
    }

    result[newLength] = '\0'; 

    MyString rezult(result);
    delete[] result;
    return rezult;  
}
MyString operator+(int number, const MyString& Str1)    
{
    const char* original = Str1.GetString();
    int originalLength = strlen(original);

    int newLength = originalLength + number;    
    char* result = new char[newLength + 1]; 

    for (int i = 0; i < number; i++)    
    {
        result[i] = 'A' + (rand() % 26);    
    }   

    for (int i = number; i < newLength; i++)    
    {
        result[i] = original[i - number];       
    }

    result[newLength] = '\0';   

    MyString rezult(result);    
    delete[] result;    
    return rezult;  
}/*
MyString& operator++(MyString& Str1)
{
    const int SIZE = strlen(Str1.GetString());  
    char* newString = new char[SIZE + 2]; 

    strcpy_s(newString, SIZE + 2, Str1.GetString());

    newString[SIZE] = '$';
    newString[SIZE + 1] = '\0';  

    delete[] Str1.GetString();
    Str1.SetString(newString);

    return Str1;
}*/
ostream& operator<<(ostream& os, const MyString& obj)   
{
    os << "#1 ostream& operator<<(ostream& os, const MyString& obj)" << endl;
    os << obj.GetString() << endl;
    return os;   
}
istream& operator>>(istream& is, MyString& Str)
{
    cout << "#2 istream& operator>>(istream& is, Foo& obj)" << endl;
    char* a = new char[100];          
    cin >> a;   
    Str.SetString(a);               
    delete[] a; 
    /*cout << "m_data = ";
    cin >> obj.m_data;

    cout << "m_character = ";
    is >> obj.m_character;*/

    return is;
}
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

    cout << "\n\n";
    cout << "Dz 2: 'operators' " << endl;   
    int NewIndex = 0;   
    String2.Print();    
    char elem = String[5];    
    cout << "#1 element: " << elem << " index: " << 5 << "\n\n";
    String2();  
    cout << "#3 ";
    String2.Print();  

    cout << "#4 String + '!':\n\n"; 
    MyString String3 = String2 + '!';         
    String3.Print(); 

   cout << "#6 '!' + String:\n";     
   String3 = '!' + String2;     
   String3.Print(); 

   cout << "#7 String + 10: \n";    
   String3 = String2 + 10;  
   String3.Print();     

   cout << "#8 10 + String: \n";    
   String3 = 10 + String2;  
   String3.Print(); 

   cout << "Dz3 \n";    
   cout << "\n\n--------------------\n\n";      
   cout << String2 << '\n'; 
   cin >> String2;  

  /* cout << "#3 ";
   String3 = String2;  
   String3.Print();*/ 
   /*cin >> obj1; 
   cout << obj1;*/


  /* String2 = String;         
   String2.Print(); */
    

/*
   String3 = String2++; 
   String3.Print();  */   
    
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
