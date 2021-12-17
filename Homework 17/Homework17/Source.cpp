#include<iostream>
#include"String.h"
#include"Timer.h"
#include<utility>
class TextView
{
public:
	TextView(const String& str)
		: m_str(std::move(str))
	{

	}
private:
	String m_str;
};
int main()
{
	Timer t;
	std::cout << "const test" << std::endl;
	String str("TEST");
	std::cout << "const world" << std::endl;
	std::cout << str.GetSize() << std::endl;
	String str2("world");
	std::cout << "assign" << std::endl;
	str = str2;
	std::cout << str << std::endl;
	std::cout << "===============\n";
	String str3;
	std::cout << "move seman1" << std::endl;
	String str4(std::move(str3));
	std::cout << "move seman2" << std::endl;
	str3 = std::move(str3);
	std::cout << "assign2" << std::endl;
	str3 = String("Hello");
	std::cout << str3 << std::endl;
	std::cout << t.elapsed() << std::endl;
	TextView txtView("Hello world");
	return 0;
}