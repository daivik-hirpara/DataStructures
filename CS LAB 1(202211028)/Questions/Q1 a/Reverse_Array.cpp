#include<stdio.h>

int swap(int *a,int *b)
{
	int temp=*a;
	*a = *b;
	*b = temp;
}
int main()
{
	int n;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter array\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("Entered array\n");
	
		for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
	
	printf("Reversed array\n");
	
	
		for(int i=0;i<=n/2;i++)
	{
	      swap(&a[i],&a[n-i-1]);
	}
	
	
	
		for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	
}
