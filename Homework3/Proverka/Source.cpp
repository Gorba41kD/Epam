#include<iostream>
#include<cmath>
using namespace std;
//Task 2
class Vector
{
public:
	int min = 0;
	double sred = 0;
	int max = 0;
	Vector():size(10)
	{
		cout << "first ";
	}
	Vector(int a)
	{
		cout << "second ";
		size = a;
	}
	void Print()
	{
		cout << "array\n";
		array = new int[size];
		for (int i = 0;i < size;i++)
		{
			cout << "print array :" << endl;
			cin >> array[i];
		}
	}
		
	void getArray()
	{
		for (int i = 0;i < size;i++)
		{
				cout << "[" << i << "] = " << array[i] << endl;
		}
		cout << endl;
	}
		
	void sortArray()
	{
		for (int i = 0;i < size;i++)
		{
			for (int j = 0;j < size - 1 - i;j++)
			{
				if (array[j] > array[j + 1])
				{
					swap(array[j], array[j + 1]);
				}
			}
		}
	}
		
	void func()
	{
		int min = array[0];
		double sred = 0;
		int max = array[0];

		for (int i = 0;i < size;i++)
		{
			if (array[i] < min)
			{
				min = array[i];
			}
			if (array[i > max])
			{
				max = array[i];
			}
			sred += array[i];
		}
		cout << "\nmin = " << min << endl;
		cout << "max = " << max << endl;
		cout << "sred = " << sred / size << endl;
	}
	void func2()
	{
		for (int i = 0;i < size;i++)
		{
			if (array[i] < 0)
			{
				array[i] = pow(array[i], 2);
			}
		}

	}
	~Vector()
	{
		delete[] array;
	}
private:
	int size;
	int* array = 0;
};
int main()
{
	Vector firstArray;
	firstArray.Print();
	cout << endl;
	firstArray.getArray();
	firstArray.sortArray();
	cout << "\t Sorted variant: " << endl;
	firstArray.getArray();
	firstArray.func();
	cout << endl;
	Vector secondArray(10);
	secondArray.Print();
	cout << endl;
	secondArray.getArray();
	secondArray.func2();
	secondArray.getArray();
	return 0;
}