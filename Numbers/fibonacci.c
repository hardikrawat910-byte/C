#include<stdio.h>
	int main()
{
	int n,i,first=0,second=1,next;
	printf("Enter a number to which you want your fibonacci series :");
	scanf("%d",&n);

	if(n>=1) printf("%d \n",first);
	if(n>=2) printf("%d \n",second);

	for(i=3;i<=n;i++)
    {
	next=first+second;
	printf("%d \n",next);
	first=second;
	second=next;
    }
	return 0;
}
