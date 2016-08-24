#include <stdio.h>

int main()
{
	char str[] = "1984";
	int year = 0;
	char *ptr = str;
	
	while(*ptr != '\0')
	{
		year = year*10 + (*ptr-0x30);
		ptr++;
	}
	printf("Given string is %s\t It's Integer value is %d\n",str,year);

}
