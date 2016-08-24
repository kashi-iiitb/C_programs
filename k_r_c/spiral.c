#include <stdio.h>
#define N 6
int main()
{
  int arr[N][N] = {{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36}};
  int i=0,j=0,k=0,m=0,l=0;
  for(i=0; i<N/2; i++)
  {
	for(j=i; j<N-i; j++)
	printf("%d ",arr[i][j]);
	j--;
	for(k=i; k<N-i; k++)
	printf("%d ",arr[k][j]);
 	for(l=j; l>=i; l--)
	printf("%d ",arr[j][l]);
	for(m=j; m>i; m--)
	printf("%d ",arr[m][i]);

  }

return 0;
}
