#include<iostream>
#include<vector>
#include<ctime>
#include<chrono>
#include<algorithm>
using namespace std;
template<typename T>
bool _bsearch(vector<T>&vec, const T& value)
{
	int size = vec.size();
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (value == vec[mid])
		{
			cout << "Value : " << value << " is located at index of " << mid << endl;
			return true;
		}
		else if (value > vec[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return false;
}
template <typename iter, typename T>
iter find_M(iter first, iter last, const T& value)
{
	for (;first != last;++first)
	{
		if (*first == value)
		{
			return first;
		}
	}
	return last;
}
template<typename T>
void inserter_sort(vector<T>& vec)
{
	T x;
	for (int i = 1;i < vec.size();++i)
	{
		x = vec[i];
		int j = i - 1;
		while (j >= 0 && x < vec[j])
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = x;
	}
}

template <typename T>
void M_sort(vector<T>& vec)
{
	for (int i = 0;i < vec.size();i++)
	{
		for (int j = 0;j < vec.size() - 1 - i;j++)
		{
			if (vec[j] > vec[j + 1])
			{
				swap(vec[j], vec[j + 1]);
			}
		}
	}
}int main()
{
	srand(time(NULL));
	vector<int>vec;
	vector<int>vec1;
	vector<int>vec2;
	vector<int>vec3;
	cout << "enter a size of vector = ";
	int size;
	cin >> size;
	for (int i = 0;i < size;++i)
	{
		vec.push_back(rand() % 100);
	}
	vec3 = vec2 = vec1 = vec1 = vec;
	cout << "\n=====================================" << endl;
	sort(vec.begin(), vec.end());
	auto myFind_start = chrono::high_resolution_clock::now();
	auto f1 = find_M(vec.begin(), vec.end(), 5);
	if (f1 != vec.end())
	{
		cout << "value is = " << *f1 << " found" << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
	auto myFind_end = chrono::high_resolution_clock::now();
	chrono::duration<double> my_FindDuration = myFind_end - myFind_start;
	cout << "my_Find Duration alg = " << my_FindDuration.count() << endl;
	cout << "=====================================" << endl;
	auto stlFind_start = chrono::high_resolution_clock::now();
	auto f2 = find(vec.begin(), vec.end(), 5);
	if (f2 != vec.end())
	{
		cout << "value is = " << *f2 << "found" << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
	auto stlFind_end = chrono::high_resolution_clock::now();
	chrono::duration<double> stlFindDuration = stlFind_end - stlFind_start;
	cout << "stl Find Duration  alg = " << stlFindDuration.count() << endl;
	cout << "=====================================" << endl;
	auto bsStart = chrono::high_resolution_clock::now();
	if (_bsearch(vec, 5))
	{
		cout << "value found" << endl;
	}
	else
	{
		cout << "value didnt find" << endl;
	}
	auto bsEnd = chrono::high_resolution_clock::now();
	chrono::duration<double> bsDuration = bsEnd - bsStart;
	cout << "Duration my bsearch = " << bsDuration.count() << endl;
	cout << "=====================================" << endl;
	auto start = chrono::high_resolution_clock::now();
	M_sort(vec1);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = end - start;
	cout << "Duration my alg = " << duration.count() << endl;
	cout << "=====================================" << endl;
	auto start1 = chrono::high_resolution_clock::now();
	sort(vec2.begin(), vec2.end());
	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<double> duration1 = end1 - start1;
	cout << "Duration stl alg = " << duration1.count() << endl;
	cout << "=====================================" << endl;
	cout << endl;
	auto ins_start = chrono::high_resolution_clock::now();
	inserter_sort(vec3);
	auto ins_end = chrono::high_resolution_clock::now();
	chrono::duration<double> ins_duration1 = ins_end - ins_start;
	cout << "Duration ins alg = " << ins_duration1.count() << endl;
	cout << "=====================================" << endl;
	return 0;
	
}