#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<ctime>
using namespace std;
class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
};
template<typename T>
class My_ptr
{
private:
	T* m_ptr;
public:
	My_ptr(T*ptr = nullptr)
		:m_ptr(ptr)
	{}
	My_ptr(const T& obj) = delete;
	My_ptr& operator =(const T& obj) = delete;
	My_ptr(T&& obj) noexcept
	{
		m_ptr = obj.m_ptr;
		obj.m_ptr = nullptr;
	}
	My_ptr& operator = (T&& obj) noexcept
	{
		if (&obj == this)
		{
			return *this;
		}
		delete m_ptr;
		m_ptr = obj.m_ptr;
		obj.m_ptr = nullptr;
		return *this;
	}
	~My_ptr()
	{
		delete m_ptr;
		m_ptr = nullptr;
	}
	T& operator*()const { return *m_ptr; }
	T* operator->()const { return m_ptr; }
};
void func()
{
	My_ptr<A> q(new A);
}
int main()
{
	func();
	return 0;

}
