#include <string> //C++�� std::string ���g������
#include <iostream>
int main()
{
	std::string s = "ABC";
	s += "DEF";
	std::cout << s << '\n';
	std::cout << s + "GHI" << '\n';
}
