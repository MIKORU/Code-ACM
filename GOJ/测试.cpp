#include <stdio.h>
int main()
{
	int k,m,n=0,p=0;
	for(k=1;k<=100;k+=2)
		p=p+k;
	printf("����֮��Ϊ%d\n",p);
	for(m=2;m<=100;m+=2)
		n=n+m;
	printf("ż��֮��Ϊ%d\n",n);
	return 0;
}