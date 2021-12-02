#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Items
{
	double weight = 0;
	double price = 0;
};
int main()
{ 
	/* Task 1 // Introductory
	vector<int> vec1;
	vector<int> vec2{ 1,2,3,4,5,6 };
	vec1.assign(vec2.begin()+vec2.size()/2, vec2.end());
	for (int i = 0;i < vec1.size();i++)
	{
		cout << vec1[i] << endl;
	}
	cout << "==============================================" << endl;*/
	 //Task 2 // Backpack
	vector<Items>vec;
	Items item;
	int numOfThings;
	cout << "Enter a number of things : " << endl;
	cin >> numOfThings;
	cout << endl;
	for (int i = 0;i < numOfThings;i++)
	{
		vec.push_back(item);
		do 
		{
			cout << "Enter a price(>=0 'r')" << endl;
			cin >> vec.at(i).price;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Oops,that input is invalid. Please try again.\n";
			}
			else
			{
				cin.ignore(32767, '\n');
			}
		} while (vec.at(i).price <= 0);
		cout << endl;
		do 
		{
			cout << "Enter a weight(>=0 kg)" << endl;
			cin >> vec.at(i).weight;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Oops,that input is invalid. Please try again.\n";
			}
			else
			{
				cin.ignore(32767, '\n');
			}
		} while (vec.at(i).weight <= 0);
		cout << endl;
	}
	for (int i = 0;i < numOfThings;i++)
	{
		cout << "The price is = " << vec[i].price << " 'r'" << endl;
		cout << "The weight is " << vec[i].weight << " kg" << endl;
		cout << endl;
	}
	cout << "==============================================" << endl;
	sort(vec.begin(), vec.end(),
		[](const Items& a, const Items& b)
		{
			return (a.weight / a.price) < (b.weight / b.price);
		});
	for (int i = 0;i < numOfThings;i++)
	{
		cout << "The price is " << vec[i].price << " 'r'" << endl;
		cout << "The weight is " << vec[i].weight << " kg" << endl;
		cout << endl;
	}
	cout << "==============================================" << endl;
	cout << "Count of things = " << vec.size() << endl;
	int number = 0;
	do
	{
		cout << "Enter the number of things that can be in the backpack (<=count of things) = ";
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Oops,that input is invalid. Please try again.\n";
		}
		else
		{
			cin.ignore(32767, '\n');
		}
	} while (number <= 0 || number > vec.size());
	cout << endl;
	vector<Items>backpack;
	copy(vec.begin(), vec.end(), back_inserter(backpack));
	backpack.resize(number);
	for (auto it = backpack.begin(); it != backpack.end();it++)
	{
		cout << "The price is " << it->price << " 'r'" << endl;
		cout << "The weight is " << it->weight << " kg" << endl;
		cout << endl;
	}

	return 0;
}