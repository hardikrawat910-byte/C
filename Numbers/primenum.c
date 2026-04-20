#include<stdio.h>
#include<math.h>
#include<stdbool.h>

	bool isprimenum(int n)
{
	if(n<=1) return false;
	if(n==2) return true;
	if(n%2==0) return false;

	for(int i=3;i*i<=n;i+=2)
    {
	if(n%i==0) return false;
    }
	return true;
}
	int main()
{
	int num;
	printf("Enter a number of your choice :");
	scanf("%d",&num);
	if (isprimenum(num))
    {
	printf("Given number %d is prime number",num);
    }
	else
    {
	printf("Given number %d is not prime number",num);
    }
	return 0;
}
