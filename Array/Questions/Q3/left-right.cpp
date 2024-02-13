#include<stdio.h>
int main()
{
	int n;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter the value of array\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+a[i];
	}
	int v=0;
    for(int i=0;i<n;i++)
	{
		v=v+a[i];
	
	    printf(" difference between sum of left and right subarray  of %d element is %d\n",i+1,(sum-(2*v)+a[i])*-1);
	} 
	return 0;
}
