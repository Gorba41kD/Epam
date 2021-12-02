#include<iostream>
#include<exception>
#include<stdexcept>
using namespace std;
class Fraction
{
private:
	double m_numerator;
	double m_denominator;
public:
	Fraction(int delimoe, int delit) :m_numerator(delimoe), m_denominator(delit)
	{
		
		if (m_denominator == 0)
		{
			throw runtime_error("Denominator can't == 0");
		}
		cout << "result = " << m_numerator / m_denominator;
	}
};
double getDenominator();
double getNumerator();
int main()
{
	double numerator = getNumerator();
	double denominator = getDenominator();
	try
	{
		if (denominator == 0)
		{
			throw exception("Denominator can't == 0");
		}
		Fraction fr(numerator, denominator);
	}
	catch (exception& exception)
	{
		cerr << "Error " << exception.what() << endl;
	}
	cout << endl;
	numerator = getNumerator();
	denominator = getDenominator();
	try
	{
		Fraction obj(numerator,denominator);
	}
	catch (exception & exception)
	{
		cerr << "Standart exception " << exception.what() << endl;
	}
	return 0;
}
double getNumerator()
{
	while (true)
	{
		double numerator;
		cout << "Enter a numerator" << endl;
		cin >> numerator;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Oops,that input is invalid.Please try again.\n";
		}
		else
		{
			cin.ignore(32767, '\n');
			return numerator;
		}
	}
}
double getDenominator()
{
	while (true)
	{
		double denominator;
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
			return denominator;
		}
	}
}