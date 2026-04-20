#include<stdio.h>
int main()
{	int a,b,t;
	printf("Enter two number you have to enter to swap" );
	scanf ("%d %d", &a , &b);
	t=a;
	a=b;
	b=t;
	printf("After swapping the two number are a is %d and b is %d",a,b);
	return 0;
}
