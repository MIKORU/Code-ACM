/*
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX_X = 100000;
int N,S[MAX_X],T[MAX_X];

struct node
{
    int first;
    int second;
}itv[MAX_X];;
bool cmp(node a,node b)
{
    if(a.first > b.first) return false;
    if(a.first < b.first) return true;
    if(a.first == b.first)
    {
        if(a.second > b.second) return true;
        if(a.second < b.second) return false;
        else return false;
    }
}
int main(){
    while(~scanf("%d",&N))
    {
        int x = 8,y = 20;
        for(int i=0;i<N;i++)
        {
            cin>>itv[i].first>>itv[i].second;
        sort(itv,itv+N,cmp);
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            if(itv[i].first <= x&&itv[i].second>=x)
            {
                ans++;
                x=itv[i].second;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX_X = 100000;
int N,S[MAX_X],T[MAX_X];

struct node
{
    int first;
    int second;
}itv[MAX_X];;
int cmp(node a,node b)
{
    return a.first<b.first;
}
int main(){
//     freopen("00.txt","r",stdin);
//    freopen("01.txt","w",stdout);
    int ans;
    int i,j;
    int maxn,cur,m;
    while(~scanf("%d",&N))
    {

        m=maxn=0;
        int x = 8,y = 20;
        int flag=0;
        int ok = 0;
        for(i=0;i<N;i++)
        {
            cin>>itv[i].first>>itv[i].second;
                if(itv[i].first<=x)
                    {ok = 1 ;itv[i].first=x;}
                if(itv[i].second>=y)
                    {flag = 1; itv[i].second=y;}
        }
        if(ok==0||flag==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        sort(itv,itv+N,cmp);
        int ans = 0;
        int i=0;
        cur = x;
        while(1)
        {
            for(;i<N;i++)
            {
                if(itv[i].first<=cur)
                {
                    if(maxn<itv[i].second)
                    {

                        maxn=itv[i].second;
                        j=i;
                    }
                }
            }
            if(maxn==cur)
            {
                ans=0;
                break;
            }
            i=j;
            cur = maxn;
            ans++;

            if(cur==y)
                break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
