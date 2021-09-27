#include<iostream>
#include<string>
// Горбачик(четный вариант - по возростанию, остаток от деления на 4 = 0 средний балл по 3 предметам)
using namespace std;
const int numberOfGrades = 3;  // Количество оценок ученика
struct student
{
	string fio;
	string name;
	int grade[3]{ 0,0,0 };
};
void showArray(const student* array, const int size);  // Прототип функции,которая показывает наш динамический массив
void sortArray(student* array, const int size);  // Прототип функции,которая сортирует наш динамический массив

int main()
{
	setlocale(LC_ALL, "RUS");
	int size = 0;
	do
	{
		cout << "enter the number of students(>=5) : " << endl;
		cin >> size;
	} while (size < 5);
	student* st = new student[size];
	for (int i = 0;i != size;i++)
	{
		cout << "enter a family : " << endl;
		cin >> st[i].fio;
		cout << "enter a name : " << endl;
		cin >> st[i].name;
		int j = 0;
		do
		{
			cout << "enter a score: " << endl;
			cin >> st[i].grade[j];
			j++;
		} while (j != numberOfGrades);
		cout << endl;
	}
	// Вывод нашего динамического массива через функцию
	showArray(st, size);
	sortArray(st, size);
	cout << "\tSorted variant :\n";
	showArray(st, size);
	delete[] st;
	return 0;
}
void showArray(const student* array, const int size)  // Определение функции,которая показывает наш динамический массив
{
	for (int i = 0; i < size;i++)
	{
		cout << array[i].fio << endl;
		cout << array[i].name << endl;
		int j = 0;
		do
		{
			cout << array[i].grade[j] << endl;
			j++;
		} while (j != numberOfGrades);
		cout << endl;
	}
}
void sortArray(student* array, const int size)  // Определение функции,которая сортирует наш динамический массив
{
	for (int i = 0;i < size;i++)
	{
		for (int j = 0;j < size - 1 - i;j++)
		{
			if ((double)((array[j].grade[0] + array[j].grade[1] + array[j].grade[2]) / numberOfGrades) > (double)((array[j + 1].grade[0] + array[j + 1].grade[1] + array[j + 1].grade[2]) / numberOfGrades))  // (double) - приведение типов в стиле C
			{
				swap(array[j], array[j + 1]);
			}
		}
	}
}

