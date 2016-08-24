#include <stdio.h>

int print_month_names(char* months[], int no_of_months)
{
  int i=0;
  //*months[0] = "January";
  for(i=0; i<no_of_months; i++)
 	printf("%s\n",months[i]);

}

int main()
{
  int i=0,no_of_months=0;
  char *months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
  no_of_months = sizeof(months)/sizeof(char*);
  print_month_names(months,no_of_months);
  char *name = "Kashi";
  printf("%s\n",name);
  *name = "Kashinath";
  printf("%s\n",name);
  //for(i=0; i<no_of_months; i++)
  //	printf("%s\n",months[i]);
return 0;
}
