#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define N 10000
int n,k,a;
int v[110],w[110];
int f[N*2+10];

void solve()
{
	for(int i=0;i<n;i++)
		scanf("%d",&v[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		w[i]=v[i]-k*a;
	}
	memset(f,-1,sizeof(f));
	f[N]=0;
	for(int i=0;i<n;i++)
	{
		if(w[i] >= 0)
		{
			for(int j=N*2;j>=w[i];j--)
				if(f[j-w[i]] != -1)
					f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
		else
		{
			for(int j=0;j-w[i] <= N*2;j++)
				if(f[j-w[i]] != -1)
					f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
	}
	if(f[N] == 0)
		f[N]=-1;
	printf("%d\n",f[N]);
}

int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    	solve();
    return 0;
}
