#include <iostream>
#include <string>

int main()
{
	std::string s{ "特記事項[納品は従来の方法で行ってください]" };
	const auto a = s.find('[');
	if (a != std::string::npos) {
		const auto start = a + 1;
		const auto b = s.find(']', start);
		if (b != std::string::npos) {
			std::cout << s.substr(start, b - start) <<'\n';
		}
	}
}
