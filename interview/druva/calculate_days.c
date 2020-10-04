#include <stdio.h>

int days_in_month[]={31,28,31,30,31,30,31,31,30,31,30,31};

struct date{
	int dd;
	int mm;
	int yyyy;
};

int calc_days(struct date *start,struct date *end){
	int days=0,months=0,years=0;
	//
	days=days_in_month[start->mm-1]-start->dd+1;
	days+=end->dd;
	for(int i=start->mm;i<end->mm;i++){
		days+=days_in_month[i];
	}
	return days;
}

int main(){
  //printf("number of months=%d\n",sizeof(days_in_month)/sizeof(int));
  struct date start = {.dd=10,.mm=3,.yyyy=1984};
  struct date end = {.dd=10,.mm=10,.yyyy=1984};
  printf("difference between the dates = %d\n",calc_days(&start,&end));
}
