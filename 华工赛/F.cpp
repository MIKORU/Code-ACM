#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 110010
using namespace std;
char a[N];
int sta[N];
int vis[N];
long long ans,l,r;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ans = l = r = 0;
        memset(vis,0,sizeof(vis));
        memset(sta,0,sizeof(sta));
        memset(a,0,sizeof(a));
        scanf("%s",a);
        int len=strlen(a);
        int tail=1;
        for(int i=0;i<len;i++)
        {
            if(tail==1) {
                sta[tail++]=i;
                vis[i]+=vis[i-1];
                continue;
            }
            if(a[i]=='(')
            {
                sta[tail++]=i;
            }
            if(a[i]==')')
            {
                if(a[sta[tail-1]]=='(') tail--;
                else sta[tail++]=i;
            }
            if(a[i]=='[')
            {
                sta[tail++]=i;
            }
            if(a[i]==']')
            {
                if(a[sta[tail-1]]=='[') {
                    tail--;
                    vis[i]=1;
                }
                else sta[tail++]=i;
            }
            vis[i]+=vis[i-1];
        }
        vis[len]+=vis[len-1];
        if(tail==1)
        {
            cout<<vis[len]-vis[0]<<endl;
            if(vis[len]-vis[0] >0 )
                cout<<a<<endl;
            continue;
        }
        sta[tail++]=len;
        sta[0]=0;
        long long slen = 0,sl,sr;
        for(int i=1;i<tail;i++)
        {
            if(ans<=vis[sta[i]]-vis[sta[i-1]])
            {
                ans=vis[sta[i]]-vis[sta[i-1]];
                if(i-1) l=sta[i-1]+1;
                else l=0;
                r=sta[i];
                //printf("%d  %d\n",l,r);
                if(r-l > slen)
                {
                    sl = l;
                    sr = r;
                    slen = r-l;
                    //printf("sl = %d  sr = %d\n",sl,sr);
                }
            }
        }
        cout<<ans<<endl;
        if(ans>0){
            for(int i=sl;i<sr;i++)
                cout<<a[i];
            cout<<endl;
        }
    }
    return 0;
}
