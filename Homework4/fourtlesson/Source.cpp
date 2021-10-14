#include<iostream>
using namespace std;
// Task 1
class Vector
{
public:
	Vector(int rows, int columns):Rows(rows),Columns(columns)
	{
		array = new int* [Rows];
		for (int i = 0;i < Rows;i++)
		{
			array[i] = new int[Columns];
		}
		for (int i = 0;i < Rows;i++)
		{
			for (int j = 0;j < Columns;j++)
			{
				cout << "Print array :" << endl;
				cin >> array[i][j];
			}
			
		}

	}
	void ShowArray()
	{
		for (int i = 0;i < Rows;i++)
		{
			for (int j = 0;j < Columns;j++)
			{
				cout << array[i][j] << "\t";
			}
			cout << endl;
		}
	}
	~Vector()
	{
		for (int i = 0;i < Rows;i++)
		{
			delete[]  array[i];
		}
		delete[] array;
	}
private:
	int sum = 0;
	int Rows;
	int Columns;
	int** array;
	friend void func(Vector &obj);
};
void func(Vector& obj);



int main()
{
	int rows = 0;
	int columns = 0;
	do
	{
		cout << "Enter a rows (>0) of array : ";
		cin >> rows;
		cout << "/nEnter a columns (>0) of array : ";
		cin >> columns;
	} while (rows <= 0 && columns <= 0);
	Vector obj(rows, columns);
	cout << endl;
	obj.ShowArray();
	cout << endl;
	func(obj);
	return 0;
}
void func(Vector& obj)
{
	for (int i = 0;i < obj.Rows;i++)
	{
		for (int j = 0;j < obj.Columns;j++)
		{
			if (obj.array[i][j] > 0)
			{
				obj.sum += obj.array[i][j];
			}
		}
	}
	cout << obj.sum;
}