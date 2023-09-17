#define _CRT_SECURE_NO_WARNINGS	

#include "MyString.h"
#include <iostream>	
using namespace std;		

static int objectCount;

MyString::MyString()
{
	lenght = 80;
	str = new char [lenght];
	str[0] = '\0'; 
	objectCount++;
}


MyString::MyString(const char* userInput) 
{
	if (str != nullptr)
	{
		delete[] str;
	}	
	char* temp = new char[strlen(userInput) + 1];
	strcpy(temp, userInput);
	str = temp;		
	objectCount++;	
}

MyString::MyString(const char* userInput, int size)		
{			
	char* newstr = new char[size + 1];
	std::cout << "Enter string: ";
	std::cin.getline(newstr, size + 1);
	if (str != nullptr) {
		delete[] str;
	} 
	str = newstr; 
	lenght = size;;
	objectCount++;	
}

void MyString::MyStrcpy(MyString& obj)
{
	if (str != nullptr) {
		delete[] str;
	}
	lenght = obj.lenght;
	str = new char[lenght + 1];
	strcpy_s(str, lenght + 1, obj.str);
}

bool MyString::MysturStr(const char* substr)
{
	return (strstr(str, substr) != nullptr);	
}

int MyString::MyChr(char c) const	
{
	int	i = 0;	
	int index = -1;	
	while (str[i] != '\0') 
	{
		if (str[i] == c) 
		{
			index = i;	
		}
		i++;	
	}
	return index;	
}

int MyString::MyStrLen() const		
{
	return strlen(str);			
}

void MyString::MyDelCat(MyString& b)	
{
	strcat(str, b.str);	
}

void MyString::MyDelCht(char c)
{
	int len = strlen(str);
	int newLen = 0;

	for (int i = 0; i < len; i++) {
		if (str[i] != c) {
			str[newLen] = str[i];
			newLen++;
		}
	}
	str[newLen] = '\0';
	lenght = newLen;
}

int MyString::MyStrCmp(MyString& b)
{
	int result = strcmp(str, b.str);

	if (result < 0) {
		return -1;
	}
	else if (result > 0) {
		return 1; 
	}
	else {
		return 0; 
	}	
}

void MyString::Print() const	
{
	cout << "String: " << str << endl;		
}
//MyString::~MyString()
//{
//	cout << "Destructor...\n";	
//	if (str != nullptr)		
//	{
//		delete[] str;	
//	}
//	objectCount--;	
//}


