#include<iostream>
#include<string>
using namespace std;
template<typename T1,typename T2>
class Currency
{
public:
	Currency()
	{
		number = 0;
		symbol = ' ';
	}
	Currency(T1 number,T2 symbol)
	{
		if (symbol == '$')
		{
			this->number = number * 2.46;
			this->symbol = 'r';
		}
		else
		{
			this->number = number;
			this->symbol = symbol;
		}
	}
	T1 GetNumber()
	{
		return number;
	}
	T2 GetSymbol()
	{
		return symbol;
	}
	Currency operator+(const Currency<T1,T2>& other)
	{
		Currency<T1,T2> temp;
		temp.number = this->number + other.number;
		temp.symbol = 'r';
		return temp;
	}
private:
	T1 number;
	T2 symbol;
};
int main()
{
	// Task Convert dollars to rubles
	double value1 = 0;
	double value2 = 0;
	do
	{
		cout << "Enter the amount of dollars(>0)" << endl;
		cin >> value1;
	} while (value1 <= 0);
	cout << endl;
	do
	{
		cout << "Enter the amount of rubles(>0)" << endl;
		cin >> value2;
	} while (value2 <= 0);
	cout << endl;
	Currency<double, char> dollars(value1,'$');
	Currency<double, char> rubli(value2, 'r');
	rubli = dollars + rubli; 
	cout << rubli.GetNumber() << rubli.GetSymbol();
	
	return 0;
}