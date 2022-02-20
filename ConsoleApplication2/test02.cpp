#include <string>
#include <iostream>
int main()
{
	//------------------as--b
	std::string s = "ABC[DEF]GHI";
	const auto a = s.find('[');
	if (a != std::string::npos) {
		const auto start = a + 1;
		const auto b = s.find(']', start);
		if (b != std::string::npos) {
			std::cout << "u" << s.substr(start, b - start) << "v\n";
		}
	}
}
