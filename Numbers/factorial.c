
#include<stdio.h>
unsigned long long factorial_ite(int n)
{
	unsigned long long int ans=1;
	for(int i=1;i<=n;i++)
	{	ans=ans*i;
	}
		return ans;
}
unsigned long long factorial_rec(int n)
{
	if(n==0)
	{ return 1;
	}
	else
	{ return n*factorial_rec(n-1);
	}
}
	int main()
{	int n;
	printf("Enter a number of your choice to find it's factorial :");
	scanf("%d", &n);
	printf("The factorial of this number %d using interative is %llu \n",n,factorial_ite(n));
	printf("The factorial of this number %d using recursive is %llu \n",n,factorial_rec(n));
	return 0;
}
