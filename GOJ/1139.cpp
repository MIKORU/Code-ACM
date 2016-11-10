#include <stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;
int a[1000005];
int main()
{
    int n,b[105],sum,i,s=1,j,c;
    while (scanf("%d",&n)!=EOF)
    {
		memset(b,0,sizeof(b));
		j=sum=0;
        if(n==0)
            break;
		for(i=0;i<n;i++)
		{
			scanf("%d",&c);
			if(!b[c])
                a[j++]=c;
			b[c]=1;
		}
		n=j;
        sort(a,a+n);
        for(i=0;i<n;i++)
        {
			if(a[n/2]>a[i])
				sum=sum+(a[n/2]-a[i]);
			else
				sum=sum+(a[i]-a[n/2]);
        }
        printf("Case #%d: %d\n",s,sum+100);
		s++;
    }

    return 0;
}