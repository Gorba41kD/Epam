#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
	////Task 1
	vector<int>vec{ 3,4,3,2,12 };
	// Task 1.1 Output of vector elements
	auto f = [&vec]()
	{
		vector<int>::iterator iter;
		for (iter = vec.begin();iter != vec.end();iter++)
		{
			cout << *iter << " ";
		}
	};
	f();
	cout << endl;
	cout << "===================================================" << endl;
	// Task 1.2 Counts the number of permutations in the vector
	int sum = 0;
	sort(vec.begin(), vec.end(), [&sum](int a, int b) 
	{
			if (a > b) 
			{ 
				sum++;
				return true; 
			}
			else 
			{ 
				return false; 
			} 
	});
	for (unsigned int i = 0;i < vec.size();i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	cout <<"number of permutations = " << sum << endl;
	cout << "===================================================" << endl;
	// Task 1.3 Searches for an occurrence of a user - supplied substring in a string
	vector<string>myVec
	{
		{"apple"},
		{"banana"},
		{"potato"},
		{"lemon"},
	};
	for (unsigned int i = 0;i < myVec.size();i++)
	{
		cout << myVec[i] << endl;
	}
	cout << endl;
	string substring;
	cout << "Enter a substring " << endl;
	cin >> substring;
	auto found{ find_if(myVec.begin(),myVec.end(),
		[&substring](string str)
		{
			return (str.find(substring) != string::npos);
		})
		};
	if (found == myVec.end())
	{
		cout << "No nuts\n";
	}
	else
	{
		cout << "Found " << *found << endl;
	}
	cout << "===================================================" << endl;
	//Task 2
	vector<int>vect;
	int a;
	int b;
	cout << "Enter the beginning of the sequence" << endl;
	cin >> a;
	cout << "Enter the end of the sequence" << endl;
	cin >> b;
	cout << endl;
	for (int i = a;i < b;i++)
	{
		vect.push_back(i);
	}
	for (auto it = vect.begin();it != vect.end();it++)
	{

		cout << *it << endl;
	}
	cout << "===================================================" << endl;
	int num;
	cout << "Enter a number = ";
	cin >> num;
	cout << endl;
	auto func{ [&vect](const int& a,const int& b,const int& num)
	{
		for (int i = b,j = 0;i < b + num;i++,j++)
		{
			vect.push_back(b + j);
		}
		vect.erase(vect.begin(), vect.begin() + num);
	} };
	func(a, b, num);
	for (auto it = vect.begin();it != vect.end();it++)
	{
		cout << *it << endl;
	}
	return 0;
}
