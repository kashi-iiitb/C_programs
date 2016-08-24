#include <stdio.h>

int main()
{
	int i=0;
	double celcius=0;
	for(i=0; i<=200; i=i+20)
	{	
		celcius = (5.0/9.0)*(i-32.0);
		printf("%d\t%6.1f\n",i,celcius);
	}
return 0;
}
