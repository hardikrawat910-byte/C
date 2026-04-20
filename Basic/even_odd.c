#include<stdio.h>
	int main()
{
	int n;
	printf("Enter a value of your choice:");
	scanf("%d",&n);
	if(n%2==0)
    {
	printf("Given value %d is even",n);
    }
	else
    {
	printf("Given value %d is odd",n);
     }


	if(n>0)
    {
	 printf("Given value %d is positve",n);
    }
	else if(n<0)
    {
	printf("Given value %d is negative",n);
    }
	else
    {
	printf("Given value %d is zero",n);
    }
	return 0;
}
