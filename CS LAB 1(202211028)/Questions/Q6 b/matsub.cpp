#include<stdio.h>
int main()
{
  int n;
  printf("Enter the n of matrix");
  scanf("%d",&n);
  
  int a[n][n];
  int b[n][n];
  int c[n][n];
  
int i,j;
 printf("Enter 1 matrix\n");
 for(i=0;i<n;i++)
 {
    for(j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
    }
 }

 
 printf("Enter 2 matrix\n");
 for(i=0;i<n;i++)
 {
    for(j=0;j<n;j++)
    {
      scanf("%d",&b[i][j]);
    }
 }
 
 for(i=0;i<n;i++)
 {
    for(j=0;j<n;j++)
    {
      
      
      c[i][j]=a[i][j]-b[i][j];
      
      
    }
    }
  printf("Subtraction of two matrix\n");
 for(i=0;i<n;i++)
 {
    for(j=0;j<n;j++)
    {
      printf("%d ",c[i][j]);
    }
    printf("\n");
 }
 
 
return 0;
  
  
  

}
