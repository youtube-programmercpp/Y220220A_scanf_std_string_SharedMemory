#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char s[3 + 1];
	if (scanf("%3s", s) == 1) {
		printf("�u%s�v\n", s);
	}
}
