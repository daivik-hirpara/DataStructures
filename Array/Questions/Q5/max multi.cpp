#include<stdio.h>
int main()
{
	int n;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	printf("Enter the array\n");
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int max=-1;
	int v=0;
	 for (int i = 1; i < n; i++) {
        int leftSum = 0;
        for (int j = i - 1; j >= 0; j--) {
            leftSum += a[j];
        }
 
        int rightSum = 0;
        for (int k = i + 1; k < n; k++) {
            rightSum += a[k];
        }
 
        if(((leftSum) * (rightSum ))>max)
        {
		max=leftSum*rightSum;
		v=i;
	    }
	}
    printf("First subarray\n");
    for(int i=0;i<v;i++)
    printf("%d",a[i]);
    printf("\n");
    printf("Second subarray\n");
    for(int i=v+1;i<n;i++)
    printf("%d",a[i]);
   return 0;
}
