#include<stdio.h>

	int main()
{
	int n ,i,arr[100],sum=0;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter %d elements for array :",n);

	for(i=0;i<=n;i++)
    {
	scanf("%d",&arr[i]);
	sum+=arr[i];
    }
	printf("The sum is %d",sum);
	return 0;
}

