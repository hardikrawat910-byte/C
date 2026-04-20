#include<stdio.h>
	int main()
{
	int n,rev=0,temp;
	printf("Enter number :");
	scanf("%d",&n);

	temp=n;
	while(n>0)
    {
	rev=rev*10+n%10;
	n/=10;
    }
	if(rev==temp)
      {
	printf("%d is palindrome",temp);
      }
	else
      {
	printf("%d is not palindrome",temp);
      }
	return 0;
}
