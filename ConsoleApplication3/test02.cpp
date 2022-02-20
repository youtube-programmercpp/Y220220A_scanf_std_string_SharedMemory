#include <iostream>
#include <string>
#include <Windows.h>
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi")
int main()
{
	std::string s{ "特記事項[納品は従来の方法で行ってください]" };

	if (const auto a = StrChrA(s.c_str(), '[')) {
		const auto start = a + 1;
		if (const auto b = StrChrA(start, ']')) {
			std::cout << "「" << std::string(start, b - start) << "」\n";
		}
	}
}
