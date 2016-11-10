#include <stdio.h>
int main()
{
	int k,m,n=0,p=0;
	for(k=1;k<=100;k+=2)
		p=p+k;
	printf("奇数之和为%d\n",p);
	for(m=2;m<=100;m+=2)
		n=n+m;
	printf("偶数之和为%d\n",n);
	return 0;
}