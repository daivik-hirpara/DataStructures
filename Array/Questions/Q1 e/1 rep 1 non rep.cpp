#include<stdio.h>
int rep(int a[],int n)
{
  	for(int i=0;i<n;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		if(a[i]==a[j])
    		{
    			
    	    return a[i];
			}
			
		}
		
	}
	return -1;	
}


int nonrep(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		if(a[i]==a[j] && i!=j)
    		break;
    		
    	    if(j==n-1)
    		return a[i];
		}
    }
    return-1;
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
	
    int c = rep(a,n);
    printf("First  repeating element is %d\n",c);
    int d = nonrep(a,n);
    printf("First  Non repeating element is %d\n",d);
	return 0;	
	}


