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
	strcpy_s(temp, strlen(Input) + 1, Input);			
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
MyString::MyString(const MyString& obj)	
{
	if (obj.str == nullptr) {
		length = 0;
		str = nullptr;
	}
	else {
		length = obj.length;
		str = new char[length];	
		for (int i = 0; i < length; i++) {	
			str[i] = obj.str[i];
		}
	}
	cout << "Copy constructor\n";
}	
//
//MyString(const MyString& obj) // 1
//{
//	lenght = obj.lenght;
//	ptr = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		ptr[i] = obj.ptr[i];
//	}
//	cout << "Copy constructor\n";
//}
MyString::MyString(MyString&& obj)
{	
	length = obj.length;	
	obj.length = 0;				
	str = obj.str;	
	obj.str = nullptr;		
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
	strcat_s(str, strlen(str) + strlen(b.str) + 1, b.str);	
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
MyString& MyString::operator=(MyString&& obj)
{
	this->str = obj.str;	
	obj.str = nullptr;	
	this->length = obj.length;	
	obj.length = 0;	
	return *this;	
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
}/*
MyString& MyString::operator=(const MyString& Str)
{
	if (this != &Str)
	{
		delete[] str;

		str = new char[length];
		length = Str.length;
		for (int i = 0; i < length; i++)	
		{
			str[i] = Str.str[i];		
		}	
		str[length-1] = '\0';	
	}
	return *this;
}*/

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
MyString::~MyString()	
{
	cout << "Destructor...\n";		
	if (str != nullptr)			
	{	
		delete[] str;			
	}
	objectCount--;		
}
