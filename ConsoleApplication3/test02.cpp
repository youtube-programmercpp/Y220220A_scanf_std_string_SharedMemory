#include <iostream>
#include <string>
#include <Windows.h>
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi")
int main()
{
	std::string s{ "���L����[�[�i�͏]���̕��@�ōs���Ă�������]" };

	if (const auto a = StrChrA(s.c_str(), '[')) {
		const auto start = a + 1;
		if (const auto b = StrChrA(start, ']')) {
			std::cout << "�u" << std::string(start, b - start) << "�v\n";
		}
	}
}
