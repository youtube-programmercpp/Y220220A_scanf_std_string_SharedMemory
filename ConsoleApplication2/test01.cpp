#include <string> //C++の std::string を使うため
#include <iostream>
int main()
{
	std::string s = "ABC";
	s += "DEF";
	std::cout << s << '\n';
	std::cout << s + "GHI" << '\n';
}
