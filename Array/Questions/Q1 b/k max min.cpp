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
	
	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<n-i-1;++j)
		{
			if(a[j]>a[j+1])
			swap(&a[j],&a[j+1]);
			
		}
	}
	printf("Enter k\n");
	int k;
	scanf("%d",&k);
	
	printf("Kth largest element is %d \n",a[n-k]);
    printf("Kth Smallest element is %d \n",a[k-1]);
	
}
