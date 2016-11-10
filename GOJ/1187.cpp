#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
//#define max(a,b) a>b?a:b
//#define min(a,b) a>b?b:a
#define N 100005
int main()
{
    //freopen("00.txt","r",stdin);
    //freopen("01.txt","w",stdout);
    int T,n,i,a[N],s,l;
    cin>>T;
    while(T--)
    {
        s=N;
        l=-N;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            s=min(s,a[i]);
            l=max(l,a[i]-s);
        }
        cout<<l<<endl;
    }
    return 0;
}
/*
#include <stdio.h>
int a[1000005]={0};
int b[1000005]={0};
int main()
{
    int msum,begi,endi,n,tsum,tbegi,tendi,i,qf,t;
    while(~scanf("%d",&t)){
    while(t--)
    {
        scanf("%d",&n);
        tsum=msum=0,qf=1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(i>1) b[i]=a[i]-a[i-1];
            //if(a[i]>=0) qf=0;
        }
        //if(qf) {printf("%d %d %d\n",0,a[1],a[n]);continue;}
        begi=endi=tbegi=tendi=b[1];
        for(i=1;i<=n;i++)
        {
            tsum+=(tendi=b[i]);

            if(tsum>msum)
            {
                msum=tsum;
                begi=tbegi;
                endi=tendi;
            }
            else if(tsum<0)
            {
                tsum=0;
                tbegi=b[i+1];
            }
        }
        printf("%d\n",msum);
    }
    }
	return 0;
}
*/
