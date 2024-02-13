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
	printf("Enter the value of array\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int v=0;
	for(int i=0;i<n;i++)
	{
	    if(a[i]<0)
	    v++;
	}
	
    for(int i=0;i<n;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		if(a[i]<0)
    		swap(&a[i],&a[j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
return 0;	
}
