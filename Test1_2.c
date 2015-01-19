#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void reverse(char *str)
{
	char *end = str;
	char tmp;
	if (str)
	{
		while (*end)
			end++;
		end--;
		while (str < end)
		{
			tmp = *str;
			*str = *end;
			*end = tmp;
			str++;
			end--;
		}
	}
}

int main()
{
	char str[] = "abc";
	reverse(str);
	printf("reverse(\"abc\") = %s\n", str);
	char str2[] = "abcdef";
	reverse(str2);
	printf("reverse(\"abcdef\") = %s\n", str2);

	return 0;
}