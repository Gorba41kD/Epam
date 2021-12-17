#include<iostream>
#include<queue>
#include<cassert>
using namespace std;
//implementation of a simple queue in the form of a dynamic array
template <typename T>
class MyQueue
{
private:
	T* ptr;
	int size;
	int capacity;
public:
	MyQueue()
	{
		size = 0;
		capacity = 0;
	}
	~MyQueue()
	{
		delete[]ptr;
		ptr = nullptr;
	}
	void Push(T value);
	T& Pop();
	bool operator == (const MyQueue& obj) const
	{
		if (Size() != obj.Size())
		{
			return false;
		}
		for (int i = 0; i < Size(); ++i)
		{
			if (ptr[i] != obj.ptr[i])
			{
				return false;
			}
		}
		return true;

	}
	bool operator!=(const MyQueue& obj) const
	{
		return !(*this == obj);
	}
	bool Empty() const
	{
		return size == 0;
	}
	T& Back();
	int Size() const
	{
		return size;
	}
	int Capacity()
	{
		return capacity;
	}
	void Clear();
	T& Front();
	friend ostream& operator<<(ostream& os, const MyQueue& myQueue);
	T& operator[](const int index)
	{
		return ptr[index];
	}
};
template<typename T>
void MyQueue<T>::Push(T value)
{
	if (capacity == 0)
	{
		capacity = size + 5;
		try
		{
			ptr = new T[capacity];
			ptr[size] = value;
			size++;
		}
		catch (bad_alloc& ex)
		{
			cerr << ex.what() << endl;
			ptr = 0;
		}
	}
	else if (size < capacity)
	{
		this->ptr[size] = value;
		++size;
	}
	else 
	{
		try
		{
			capacity *= 2;
			T* ptr2 = new T [capacity];
			for (int i = 0;i < size;i++)
			{
				ptr2[i] = ptr[i];
			}
			ptr2[size] = value;
			++size;
			delete[] ptr;
			ptr = ptr2;
		}
		catch (bad_alloc& ex)
		{
			cerr << ex.what();
			ptr = 0;
		}
	}

}

template<typename T>
T& MyQueue<T>::Pop()
{	
	assert(size > 0 && "Pop back on empty queue!");
	T item;
	item = ptr[0];
	try 
	{
		T* ptr2 = new T[--size];
		size--; 
		for (int i = 0; i < size; i++)
		{
			ptr2[i] = ptr[i + 1];
		}
		if (size > 0)
		{
			delete[] ptr;
		}
		ptr = ptr2;
		return item;
	}
	catch (bad_alloc& exc)
	{
		cout << exc.what() << endl;
	}
}

template<typename T>
T& MyQueue<T>::Back()
{
	return ptr[--size];
}

template<typename T>
void MyQueue<T>::Clear()
{
	size = 0;
}

template<typename T>
T& MyQueue<T>::Front()
{
	return ptr[0];
}
template<typename T>
ostream& operator<<(ostream& os, const MyQueue<T>& myQueue)
{
	os << MyQueue<T>::ptr[myQueue];
	return os;
}
int main()
{
	MyQueue<int> q;
	for (int i = 0;i < 5;i++)
	{
		q.Push(i);
	}
	for (int i = 0;i < q.Size();++i)
	{
		cout << q[i] << " ";
	}
	cout << endl;
	q.Pop();
	for (int i = 0;i < q.Size();++i)
	{
		cout << q[i] << " ";
	}
	cout << endl;
	cout << q.Back() << endl;
	cout << q.Front() << endl;
	return 0;
}
