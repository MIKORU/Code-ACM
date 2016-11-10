#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <limits.h>
#define N 100000
using namespace std;
const int maxn=2000005;
int n;
int dat2[maxn<<2];
int f(int a)
{
    int s=1;
    while(a>1)
    {
        if(a%2==1)
            a=a*3+1;
        else
            a/=2;
        s++;
    }
    return s;
}
void init(int n_)
{
	n=1;
	while(n<n_)n*=2;

	for(int i=0;i<2*n-1;i++)
    {
		dat2[i]=-1;
	}
}
void update(int k,int a){
	k+=n-1;
	dat2[k]=a;
	while(k>0)
    {
		k=(k-1)/2;
		dat2[k]=max(dat2[k*2+1],dat2[k*2+2]);
	}
}
int query2(int a,int b,int k,int l,int r)
{
	if(r<a||l>b){
		return -1;
	}
	if(a<=l&&b>=r){
		return dat2[k];
	}else{
		int v1=query2(a,b,k*2+1,l,(l+r)/2);
		int v2=query2(a,b,k*2+2,(l+r)/2+1,r);
		return max(v1,v2);
	}
}
int main()
{
    int m,i,j,s,k,a,b;
//	freopen("00.txt", "r", stdin);
//    freopen("01.txt","w", stdout);
		init(N);
		for(i=1;i<=N;i++)
        {
			update(i,f(i));
		}
		while(scanf("%d",&m)!=EOF)
        {
            while(m--)
            {
                scanf("%d%d",&a,&b);
                printf("%d\n",query2(a,b,0,0,n-1));
            }
        }
	return 0;
}
