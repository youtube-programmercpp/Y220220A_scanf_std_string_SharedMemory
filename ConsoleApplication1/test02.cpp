#include <stdio.h>
int main()
{
	char s[3 + 1];
	if (scanf_s("%3s", s, (int)sizeof s) == 1) {
		printf("�u%s�v\n", s);
	}
}
