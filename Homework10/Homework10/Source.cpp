#include<iostream>
#include<exception>
using namespace std;
double func(double numerator, double denominator)
{
	if (denominator == 0)
	{
		throw "Denominator can't == 0";
	}
	return numerator/denominator;
}
int main()
{
	double numerator = 0;
	double denominator = 0;
	double result = 0;
	while (true)
	{
		cout << "Enter a numerator" << endl;
		cin >> numerator;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767,'\n');
			cout << "Oops,that input is invalid.Please try again.\n";
		}
		else
		{
			cin.ignore(32767, '\n');
			break;
		}
	}
	while (true)
	{
		cout << "Enter a denominator" << endl;
		cin >> denominator;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Oops,that input is invalid.Please try again.\n";
		}
		else
		{
			cin.ignore(32767, '\n');
			break;
		}
	}
	try
	{
		result = func(numerator, denominator);
		cout << "The result of the expression is " << result << endl;
	}
	catch (const char* exception)
	{
		cerr << "Error: " << exception << endl;
	}
	return 0;
}