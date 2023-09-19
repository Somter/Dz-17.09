#pragma once
class MyString
{
private:
	char* str;
	int length;
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

	char& operator[](const int index);	
	void operator() ();	
	//MyString& operator=(const MyString& Str);		

	char* GetString() const;			
	void SetString(char* str);				

	void Print() const;							
	//~MyString();			
};	

