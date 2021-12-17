#include "String.h"
String::String()
{
	log("construktor");
	m_str = nullptr;
	m_size = 0;
}
String::String(const char* str)
{
	log("construktor with param");
	m_size = strlen(str);
	m_str = new char[m_size + 1];
	for (int i = 0;i < m_size;i++)
	{
		m_str[i] = str[i];
	}
	m_str[m_size] = '\0';
}
String::~String()
{
	log("destruktor");
	delete[]m_str;
	m_str = nullptr;
}

char& String::operator[](const int index)
{
	return m_str[index];
}

int String::GetSize() const
{
	return m_size;
}
String& String::operator=(const String& obj)
{
	log("copy assigment operator");
	if (&obj == this)
	{
		return *this;
	}
	if (m_str != nullptr)
	{
		delete[] m_str;
	}
	m_size = strlen(obj.m_str);
	m_str = new char[m_size + 1];
	for (int i = 0;i < m_size;i++)
	{
		m_str[i] = obj.m_str[i];
	}
	m_str[m_size] = '\0';
	return *this;
}
String String::operator+(const String& obj)
{
	String newM_str;
	newM_str = new char[m_size + obj.m_size + 1];
	int i = 0;
	for (; i < m_size;++i)
	{
		newM_str.m_str[i] = m_str[i];
	}
	for (int j = 0; j < obj.m_size;++i,j++)
	{
		newM_str[i] = obj.m_size;
	}
	newM_str[m_size + obj.m_size] = '\0';
	return newM_str;
}
std::ostream& operator<<(std::ostream& out, const String& obj)
{
	for (int i = 0;i < obj.m_size;i++)
	{
		out << obj.m_str[i];
	}
	return out;
}
String::String(const String& obj)
{
	log("construktor copy");
	m_size = obj.m_size;
	m_str = new char[obj.m_size + 1];
	for (int i = 0; i < m_size; i++)
	{
		m_str[i] = obj.m_str[i];
	}
	m_str[m_size] = '\0';
}

String::String(String&& obj)noexcept
	:m_size(obj.m_size)
	,m_str(obj.m_str)
{
	log("construktor perem");
	obj.m_size = 0;
	obj.m_str = nullptr;
}

String& String::operator=(String&& obj) noexcept
{
	log("perem operator =");
	if (&obj == this)
	{
		return *this;
	}
	if (m_str != nullptr)
	{
		delete[]m_str;
	}
	m_size = obj.m_size;
	m_str = obj.m_str;
	obj.m_size = 0;
	obj.m_str = nullptr;
	return *this;
}
