#pragma once
class MyString
{
private:
	char* str;
	int lenght;
public:
	MyString();	
	MyString(const char* str);	
	MyString(const char* str, int size);	
	void MyStrcpy(MyString& obj);	
	bool MysturStr(const char* substr);
	int MyChr(char c) const;
	int MyStrLen() const;	
	void MyDelCat(MyString& b);		 
	void MyDelCht(char c);
	int MyStrCmp(MyString& b);	

	void Print() const;				
	//~MyString();		
};	

