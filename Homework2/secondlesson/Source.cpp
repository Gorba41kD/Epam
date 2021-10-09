#include<iostream>
#include<string>
using namespace std;
//Task number 1
class String
{
public:
	String(string parametr)
	{
		word = parametr;
	}
	void func()
	{
		char lastSymbol = word[word.length() - 1];
		for (int i = 0;i < word.length();i++)
		{
			if (word[i] == 'a')
			{
				word[i] = lastSymbol;
				numOfReplacements++;
			}
		}
		cout << word;
		
	}
	int GetNumOfReplacements()
	{
		return numOfReplacements;
	}
	~String()
	{

	}
private:
	int numOfReplacements = 0;
	string word;

};
int main()
{
	string yourWord;
	do
	{
		cout << "Please enter a word,last symbol != 'a'" << endl;
		cout << "Your word is ";
		cin >> yourWord;
	} while (yourWord[yourWord.length() - 1] == 'a');
	String value(yourWord);
	cout << "\tChanged word :\n";
	value.func();
	cout << "\nNumber of replacements : " << value.GetNumOfReplacements();
	return 0;
}