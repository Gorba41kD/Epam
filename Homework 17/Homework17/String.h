#pragma once
#include<iostream>
class String
{
private:
	char* m_str;
	int m_size = 0;
	void log(const char* msg)
	{
		std::cout << "[" << this << "] " << msg << " [" << *this << "]" << "\n";
	}
public:
	String();
	String(const char *str);
	String(const String& obj);
	String(String&& obj)noexcept;
	String& operator =(String&& obj)noexcept;
	~String();
	char& operator[](const int index);
	int GetSize()const;
	friend std::ostream& operator <<(std::ostream& out,const String& obj);
	String& operator = (const String& obj);
	String operator +(const String& obj);
};

