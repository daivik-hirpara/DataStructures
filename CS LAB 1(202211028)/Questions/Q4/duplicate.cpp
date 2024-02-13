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
    
 //bubble sort	
	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<n-i-1;++j)
		{
			if(a[j]>a[j+1])
			swap(&a[j],&a[j+1]);
			
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			a[j]=0;
		}
	}
	    int b[n];
	    int k=0;
		for(int i=0;i<n;i++)
	{
	         if(a[i]!=0)
	        
	         b[k++]=a[i];
	        
	}
	
    	for(int i=0;i<k;i++)
	{
		printf("%d",b[i]);
	}
	return 0;
}
