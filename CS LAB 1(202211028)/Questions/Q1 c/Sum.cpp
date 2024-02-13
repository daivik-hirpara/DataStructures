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
	
	int k;
	printf("Enter the k\n");
	
	scanf("%d",&k);
	
	for(int i=0;i<n;i++)
	{ 
	    int sum =a[i];
	    if(sum == k)
	    {
		
	    printf("Sub array is %d\n",a[i]);
	    
	    break;
	    
	    }
	    else
	    {
		
		for(int j=i+1;j<n;j++)
		{
		 sum  = sum +a[j];
		  if(sum  == k)
		  {
		  	printf("Sub array is \n");
		  	for(int k=i;k<=j;k++)
		  	{
		  		printf("%d",a[k]);
			  }
			  printf("\n");
			  return 0;
		  }
		  
			
		}
		
	    }
	}
	
	printf("No sub array found\n");
}
