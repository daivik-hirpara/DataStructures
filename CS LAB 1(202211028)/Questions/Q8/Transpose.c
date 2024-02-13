#include<stdio.h>
int main()
{
int n;
 printf("Enter the value of n\n");
 scanf("%d",&n);
 
 int a[n][n];
 int i,j;
 printf("Enter values\n");
 for(i=0;i<n;i++)
 {
    for(j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
    }
 }
 printf("without additional matrix\n");
 for(i=0;i<n;i++)
 {
    for(j=0;j<n;j++)
    {
      if(j>i)
      {
           int temp;
           temp=a[i][j];
           a[i][j]=a[j][i];
           a[j][i]=temp;
      }
    }
 }
 for(i=0;i<n;i++)
 {
    for(j=0;j<n;j++)
    {
      printf("%d",a[i][j]);
    }
    printf("\n");
 }
 
 return 0;
}
