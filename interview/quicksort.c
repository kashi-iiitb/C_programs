#include <stdio.h>
#define SIZE 10

int print_arr(int arr[],int size);
int quick_sort(int arr[], int start, int end);
int main()
{

 int arr[SIZE] = {4,3,6,7,1,10,9,8,2,5};
 int i=0;
 printf("Array before sorting: ");
 print_arr(arr,SIZE);
 quick_sort(arr,0,SIZE-1);
 printf("Array after sorting: ");
 print_arr(arr,SIZE);
 
 return 0;
}

int print_arr(int arr[], int size)
{
 int i=0;
 for(i=0; i<size; i++)
	printf("%d ",arr[i]);
 printf("\n");
}

int quick_sort(int arr[], int start, int end)
{
  if(start >= end)
	return;
  int i=start;
  int j=end;
  int a = arr[start];
  int temp=0;
  while(j>i)
 {
	while(arr[i] <= a && i<j)
		i++;
	while(arr[j] > a)
		j--;
	if(j>i)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
 }
 
		temp = arr[j];
		arr[j] = arr[start];
		arr[start] = temp;
  quick_sort(arr,start,j-1);
  quick_sort(arr,j+1,end);

}
