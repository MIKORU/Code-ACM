/*Problem Description:

  小明非常喜欢数学，又要来做数学题了，今天的问题很简单，是求中位数。给定一个空集合和一些数，每次把数插入集合时输出集合内的中位数。
（中位数的概念是：如果集合有奇数个数，给出排序后处在最中间的那个数；如果是偶数个数，给出排序后最中间两个数的均值。）
Input:

输入包含多组测试，每组测试首先输入一个整数n(0<=n<=100000)，代表有n个整数，接下来输入n个整数（int范围内）到集合里。

Output:

对于每组测试，每次插入集合输出集合的中位数。
Sample Input:

5
3 5 7 6 1
Sample Output:

3 4 5 5.5 5*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iostream>
#define N 100005
int a[100000];
using namespace std;
int main()
{
    int n,t,m,i,j,x,y,s;
    while(cin>>n)
    {

        priority_queue<int>st;
        while(n--)
        {
            y=0;
            cin>>t;
            st.push(t);
            m=st.size();
            //cout<<m<<endl;
            x=m/2;
            cout<<x<<endl;
            if(m%2)
            {
                while(x--)
                {
                    s=1;
                    a[y]=st.top();
                    cout<<"每个值a【y】"<<a[y]<<endl;
                    st.pop();
                    y++;
                }
                cout<<st.top()<<endl;
                if(s==1)
                {for(y;y>=0;y--)
                    st.push(a[y]);}
            }
            else
            {
                x=x-1;
                while(x--)
                {
                    s=1;
                    a[y]=st.top();
                    cout<<"每个值a【y】"<<a[y]<<endl;
                    st.pop();
                    y++;
                }
                a[y++]=i=st.top();
                st.pop();
                j=st.top();
                cout<<i<<" "<<j<<endl;
                if((i+j)%2!=0)
                    cout<<(i+j)/2<<".5"<<endl;
                else cout<<(i+j)/2<<endl;
                if(s==1)
                {for(y;y>=0;y--)
                    st.push(a[y]);}
            }

        }
    }
    return 0;
}


/*
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 0x7FFFFFFF
#define eps 10^(-6)
#define Q_CIN ios::sync_with_stdio(false);
#define REP( i , n ) for ( int i = 0 ; i < n ; ++ i )
#define FOR( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define CLR( a , x ) memset ( a , x , sizeof (a) )
#define RE freopen("1.txt","r",stdin);
#define WE freopen("2.txt","w",stdout);
#define MOD 10009
#define NMAX 10002
#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)<(b)?(b):(a))

multiset<int>s;
int main()
{
  //  RE
    int n,m,num;
    while(cin>>n)
    {
        int ans;
        s.clear();
        int cnt=1;
        cin>>num;
        s.insert(num);
        multiset<int>::iterator it=s.begin();

        printf("%d",*it);
        FOR(i,2,n)
        {
            cin>>num;
            int flag=0;
            s.insert(num);
            cnt++;
            if(cnt%2)       //偶->奇
            {
                if(num>=*it){           //下一个数
                    printf(" %d",*(++it));
                    continue;
                }
                else                   //不变
                    ans=*it;
            }
            else            //奇->偶
            {
                if(num>=*it)        //(原本的中位数+下一个数)/2
                {
                    multiset<int>::iterator pt=it;
                    pt++;
                    int tmp=*it+*pt;
                    if(tmp%2==0)
                         printf(" %d",tmp/2);
                    else
                        printf(" %d.5",tmp/2);
                    continue;
                }
                else {              //(原本的中位数+上一个数)/2
                    multiset<int>::iterator pt=it;
                    it--;           //指向上一个较小的数
                    int tmp=*it+*pt;
                    if(tmp%2==0)
                         printf(" %d",tmp/2);
                    else
                        printf(" %d.5",tmp/2);
                    continue;
                }
            }
            printf(" %d",ans);
        }
        printf("\n");
    }
    return 0;
}
