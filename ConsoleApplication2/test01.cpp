#include <string> //C++‚Ì std::string ‚ðŽg‚¤‚½‚ß
#include <iostream>
int main()
{
	std::string s = "ABC";
	s += "DEF";
	std::cout << s << '\n';
	std::cout << s + "GHI" << '\n';
}
