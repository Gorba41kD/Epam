#include<iostream>
#include<string>
using namespace std;
//Task:
//1. Determine the combined(structural) type containing information about the student : surname, first name, faculty, group, e - mail.
//2. Allocate a static memory array for 30 students.
//3. Allocate a dynamic memory array for a previously unknown number of students.
//4. Get access to the first student from the array using pointer dereference.
//5. Calculate the memory size occupied by the array of students.
//6. Iterate through the array of students using the pointer increment.Output the address of each student structure in memory to the console.Print a message about the value by which the pointer value changes during increment.
//7. Output the addresses of neighboring fields of the structure to the console.
//8. Create a structure with the same set of fields, but a different sequence.Compare the sizes of structures.Output the addresses of each field for both structures to the console.Draw conclusions.
struct Student
{
	string m_family;
	string m_name;
	string m_faculty;
	string m_email;
	int m_num = 0;
private:
	friend ostream& operator << (ostream& out, const Student& st);
};
struct AnotherStudent
{
	int m_num = 0;
	string m_family;
	string m_name;
	string m_faculty;
	string m_email;
};

ostream& operator<< (ostream& out, const Student& st);
int main()
{
	Student array[30]{};
	int size = 0;
	do
	{
		cout << "enter the number of students : " << endl;
		cin >> size;
	} while (size <= 0);
	Student* st = new Student[size];
	for (int i = 0;i < size;i++)
	{
		cout << "Enter a family name : " << endl;
		cin >> st[i].m_family;
		cout << "Enter a name : " << endl;
		cin >> st[i].m_name;
		cout << "Enter a faculty : " << endl;
		cin >> st[i].m_faculty;
		cout << "Enter a number of group : " << endl;
		cin >> st[i].m_num;
		cout << "Enter a email : " << endl;
		cin >> st[i].m_email;
	}
	cout << endl;
	// 4
	cout << *st << endl;
	// 5
	cout << sizeof(st) << endl;
	// 6
	for (int i = 0;i < size;i++)
	{
		cout <<"adress is : " << st + i << endl;
		cout <<" changes to = " << (st + i) - st << endl;
	}
	cout << endl;
	// 7
	for (int i = 0;i < size;i++)
	{
		cout << "adress is : " << st + i << endl;
	}
	cout << endl;
	//8
	AnotherStudent* anSt = new AnotherStudent[size];
	for (int i = 0;i < size;i++)
	{
		cout << "Enter a family name : " << endl;
		cin >> anSt[i].m_family;
		cout << "Enter a name : " << endl;
		cin >> anSt[i].m_name;
		cout << "Enter a faculty : " << endl;
		cin >> anSt[i].m_faculty;
		cout << "Enter a number of group : " << endl;
		cin >> anSt[i].m_num;
		cout << "Enter a email : " << endl;
		cin >> anSt[i].m_email;
	}
	if (sizeof(Student) - sizeof(AnotherStudent) > 0)
	{
		cout << "> 0" << endl;
	}
	else if (sizeof(Student) - sizeof(AnotherStudent) == 0)
	{
		cout << "= 0" << endl;
	}
	else
	{
		cout << "< 0" << endl;
	}
	for (int i = 0;i < size;i++)
	{
		cout << &(st[i].m_family) << endl;
		cout << &(st[i].m_name) << endl;
		cout << &(st[i].m_faculty) << endl;
		cout << &(st[i].m_num) << endl;
		cout << &(st[i].m_email) << endl;
		
		
	}
	cout << "========================" << endl;
	for (int i = 0;i < size;i++)
	{
		cout << &(anSt[i].m_family) << endl;
		cout << &(anSt[i].m_name) << endl;
		cout << &(anSt[i].m_faculty) << endl;
		cout << &(anSt[i].m_num) << endl;
		cout << &(anSt[i].m_email) << endl;
	}
	delete[] st;
	st = nullptr;
	return 0;

}
ostream& operator<<(ostream& out, const Student& st)
{
	out << "Family is : " << st.m_family << " Name is : " << st.m_name << " Facylty is : " << st.m_faculty << " Number of group is : " << st.m_num << " Email is : " << st.m_email;
	return out;
}

