#define _CRT_SECURE_NO_WARNINGS	

#include "MyString.h"
#include <iostream>	
#include <cstring>	
using namespace std;		

static int objectCount;

MyString::MyString()
{
	length = 80;
	str = new char [length];	
	str[0] = '\0'; 
	objectCount++;
}
MyString::MyString(const char* Input) 
{

	if (str != nullptr)	
	{
		delete[] str;	
	}
	str = nullptr;
	char* temp = new char[strlen(Input) + 1];
	strcpy(temp, Input);	
	str = temp;
	objectCount++;
}

MyString::MyString(const char* Input, int size)		
{
	if (str != nullptr)	
	{
		delete[] str;	
	}	
	str = nullptr; 
	char* newstr = new char[size + 1];		
	cout << "Enter string: ";	
	cin.getline(newstr, size + 1);		
	str = newstr;	
	length = size;	
	objectCount++;	
}

void MyString::MyStrcpy(MyString& obj)
{
	if (str != nullptr) {
		delete[] str;
	}
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
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
	length = newLen;
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

char& MyString::operator[](const int index) {		
	if (index >= 0 && index < length) {
		return str[index];	
	}	
	return str[0];
}
void MyString::operator() ()
{
	if (str != nullptr)
	{
		delete[] str;
	}
	str = new char[length];
	cin.getline(str, length);
}
//MyString& MyString::operator=(const MyString& Str)
//{
//	if (this != &Str)
//	{
//		delete[] str;
//
//		str = new char[Str.length + 1];
//		length = Str.length;
//		strcpy_s(str, length + 1, Str.str);
//	}
//	return *this;
//}	
char* MyString::GetString()	const	
{
	return str;			
}
void MyString::SetString(char* str)
{
	this->str = str;
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


