#include<stdio.h>
int main()
{
  int n;
  printf("Enter the n of matrix");
  scanf("%d",&n);
  
  int a[n][n];
  int b[n][n];
  int c[n][n];
  
  int i,j,k;
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
      c[i][j]=0;
      for(k=0;k<n;k++)
      {
      c[i][j]+=a[i][k]*b[k][j];
      }
      
    }
    }
 printf("Multiplication of two matrix\n");
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
