#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
struct Ñlerk
{
	std::string fam;
	std::string name;
	std::string patr;
	int date = 0;
	int month = 0;
	int year = 0;
	std::string gender;
	friend std::istream& operator >> (std::istream& is, Ñlerk& clerk);
	friend std::ostream& operator << (std::ostream& out, const Ñlerk& clerk);
};
std::istream& operator >> (std::istream& is, Ñlerk& clerk)
{
	is >> clerk.fam >> clerk.name >> clerk.patr >> clerk.date >> clerk.month >> clerk.year >> clerk.gender;
	return is;
}
std::ostream& operator << (std::ostream& out, Ñlerk& clerk)
{
	out 
		<< "Surname : " << clerk.fam << "\n" 
		<< "Name : " << clerk.name << "\n" 
		<< "Partonymic : " << clerk.patr << "\n" 
		<< "Date : " << clerk.date << "\n" 
		<< "Month : " << clerk.month << "\n" 
		<< "Year : " << clerk.year << "\n" 
		<< "Gender : " << clerk.gender << "\n";
	return out;
}
void Func()
{
	std::cout << "\Select action:" << std::endl;
	std::cout << "1 - Load data from file" << std::endl;
	std::cout << "2 - Data output to the screen" << std::endl;
	std::cout << "3 - Sorting the database alphabetically (by surname)" << std::endl;
	std::cout << "4 - Output : list of people born in a given month" << std::endl;
	std::cout << "5 - Output : all surnames starting with a given letter" << std::endl;
	std::cout << "6 - Output : the surname of the oldest man" << std::endl;
	std::cout << "0 - Exit the program" << std::endl;
}
int main()
{
	setlocale(LC_ALL, "RUS");
	std::string path = "myFile.txt";
	std::ifstream fin;
	std::vector<Ñlerk>vec;
	std::string stroka;
	Ñlerk clerk;
	int month = 0;
	int value = 0;
	Func();
	int action = 0;
	do
	{
		while (true)
		{
			std::cout << "Enter a action : ";
			std::cin >> action;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Oops,that input is invalid.Please try again\n";
			}
			else
			{
				std::cin.ignore(32767, '\n');
				break;
			}
		}
		std::cout << std::endl;
		switch (action)
		{
		case 1:
			fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
			try
			{
				fin.open(path);
				while (!fin.eof())
				{
					fin >> clerk;
					vec.push_back(clerk);
					
				}
				std::cout << "File is open" << std::endl << std::endl;
				fin.close();
			}
			catch (const std::exception& exc)
			{
				std::cerr << exc.what() << std::endl;
				std::cerr << "File open error" << std::endl;
			}
			break;
		case 2:
			if (!vec.empty())
			{
				for (int i = 0; i < vec.size();i++)
				{
					std::cout << vec[i] << std::endl;
				}
				Func();
			}
			else
			{
				std::cout << "Look at the first point" << std::endl << std::endl;
			}
			break;
		case 3:
			if (!vec.empty())
			{
				std::cout << "=================SORTED VARIANT=========================" << std::endl;
				sort(vec.begin(), vec.end(),
					[](const Ñlerk& a, const Ñlerk& b)
					{
						return a.fam < b.fam;
					}
				);
				std::cout << std::endl;
				for (int i = 0;i < vec.size();++i)
				{
					std::cout << vec[i] << std::endl;
				}
				Func();
			}
			else
			{
				std::cout << "Look at the first point" << std::endl << std::endl;
			}
			break;
		case 4:
			if (!vec.empty())
			{
				do
				{
					std::cout << "\nEnter the month ";
					std::cin >> month;
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						std::cout << "Oops,that input is invalid. Please try again.\n";
					}
					else
					{
						std::cin.ignore(32767, '\n');
					}
				} while (month <= 0 || month > 12);
				std::cout << std::endl;
				for (unsigned int i = 0;i < vec.size();i++)
				{
					if (vec[i].month == month)
					{

						value++;
					}
				}
				if (value == 0)
				{

					std::cout << "Not on the list" << std::endl << std::endl;
				}
			}
			else
			{
				std::cout << "Look at the first point" << std::endl << std::endl;
			}
			break;
		case 5:
			if (!vec.empty())
			{
				std::cout << "\nEnter letter ";
				std::cin >> stroka;
				std::cin.ignore(32767, '\n');
				std::cout << std::endl;
				value = 0;
				for (unsigned int i = 0;i < vec.size();i++)
				{
					if (vec[i].fam.find(stroka) == 0)
					{
						std::cout << vec[i] << std::endl;
						value++;
					}
				}
				if (value == 0)
				{
					std::cout << "Not on the list" << std::endl << std::endl;
				}
				Func();
				std::cout << std::endl;
			}
			else
			{
				std::cout << "Look at the first point" << std::endl << std::endl;
			}
			break;
		case 6:
			if (!vec.empty())
			{
				auto iter{ max_element(vec.begin(),vec.end(),
					[](const Ñlerk& a,const Ñlerk& b)->int
					{
						if (a.year > b.year && a.gender == "m" && b.gender == "m")
						{
							return true;
						}
						else if (a.year == b.year)
						{
							if (a.month > b.month)
							{
								return true;
							}
							else if (a.month == b.month)
							{
								if (a.date > b.date)
								{
									return true;
								}
								else
								{
									return false;
								}
							}
							else
							{
								return false;
							}
						}
						else
						{
							return false;
						}
					}) };
				std::cout << "\tThe oldest man is : " << std::endl;
				std::cout << "Surname : " << iter->fam << std::endl;
				std::cout << "Name : " << iter->name << std::endl;
				std::cout << "Partonymic : " << iter->patr << std::endl;
				std::cout << "Date : " << iter->date << std::endl;
				std::cout << "Month : " << iter->month << std::endl;
				std::cout << "Year : " << iter->year << std::endl;
				std::cout << "Gender : " << iter->gender << std::endl;
				std::cout << std::endl << std::endl;
				Func();
				std::cout << std::endl;
			}
			else
			{
				std::cout << "Look at the first point" << std::endl << std::endl;
			}
			break;
		}
	} while (action != 0);
	return 0;
}