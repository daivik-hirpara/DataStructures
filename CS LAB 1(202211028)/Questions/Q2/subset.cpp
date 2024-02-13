#include<stdio.h>
int main()
{
	
	int n1,n2;
	int v=0;
	printf("Enter the value of n1,n2 \n");
	scanf("%d %d",&n1,&n2);
	
	int a1[n1];
	printf("Enter the value of array A1\n");
	for(int i=0;i<n1;i++)
	{
		scanf("%d",&a1[i]);
	}
	
	int a2[n2];
	printf("Enter the value of array A2\n");
	for(int i=0;i<n2;i++)
	{
		scanf("%d",&a2[i]);
	}
	
	
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			if(a1[i]!=a2[j])
			{
		       v=0;
			}
			else{
			
		     v=1;
		}
			
		}
	}
	if(v==0)
	printf("no\n");
	else
	printf("yes\n");
	return 0;
}
	
