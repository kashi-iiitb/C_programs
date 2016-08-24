#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int Merge(int ar[],int start, int mid, int midplus1, int end);

int print_arr(int arr[], int size)
{
 int i=0;
 for(i=0; i<size; i++)
	printf("%d ",arr[i]);
 printf("\n");
}

int MergeSort(int arr[],int start, int end)
{
  int mid = 0;
  if(start >= end)
	return;
  mid = (start+end)/2;
  MergeSort(arr,start,mid);
  MergeSort(arr,mid+1,end);
  Merge(arr,start, mid, mid+1, end);

}

int Merge(int arr[],int start, int mid, int midplus1,int end)
{

	int *temp = (int *)malloc(sizeof(end-start)+1);
	int i = start;
	int j = midplus1;
	int k=0;
	int index = 0;
	while(i<=mid && j<=end)
	{
		if(arr[i]<arr[j])
			temp[index++] = arr[i++];
		else
			temp[index++] = arr[j++];
		
	}
	if(i<=mid)
		while(i<=mid)
			temp[index++] = arr[i++];
	if(j<=end)
		while(j<=end)
			temp[index++] = arr[j++];
	for(k=start; k<=end; k++)
		arr[k] = temp[k-start];
	
}

int main()
{
 int arr[] = {4,3,5,6,8,9,7,10,2,1};
 //int arr[] = {4,3,5,6};
 
 print_arr(arr,SIZE);
 MergeSort(arr,0,SIZE-1);
 print_arr(arr,SIZE);
 
 return 0;
}
