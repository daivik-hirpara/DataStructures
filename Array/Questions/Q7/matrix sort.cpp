#include<stdio.h>
int swap(int *a,int *b)
{
	int temp=*a;
	*a = *b;
	*b = temp;
}
int main()
{
  int m,n;
  printf("Enter the value of m and n of matrix");
  scanf("%d %d",&m,&n);
  int a[m][n];

 printf("Enter  matrix\n");
 for(int i=0;i<m;i++)
 {
    for(int j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
    }
 }
 int b[m*n];
 
  for(int i=0;i<m;i++)
 {
    for(int j=0;j<n;j++)
    {
         b[(n*i)+j] = a[i][j];
    }
 }
 for(int i=0;i<m*n-1;++i)
	{
		for(int j=0;j<m*n-i-1;++j)
		{
			if(b[j]>b[j+1])
			swap(&b[j],&b[j+1]);
			
		}
	}
 
  for(int i=0;i<m*n;i++)
 {
      printf("%d ",b[i]);
 }
 return 0;
}
