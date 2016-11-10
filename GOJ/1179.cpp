/*Problem Description:

  С���ǳ�ϲ����ѧ����Ҫ������ѧ���ˣ����������ܼ򵥣�������λ��������һ���ռ��Ϻ�һЩ����ÿ�ΰ������뼯��ʱ��������ڵ���λ����
����λ���ĸ����ǣ����������������������������������м���Ǹ����������ż��������������������м��������ľ�ֵ����
Input:

�������������ԣ�ÿ�������������һ������n(0<=n<=100000)��������n������������������n��������int��Χ�ڣ��������

Output:

����ÿ����ԣ�ÿ�β��뼯��������ϵ���λ����
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
                    cout<<"ÿ��ֵa��y��"<<a[y]<<endl;
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
                    cout<<"ÿ��ֵa��y��"<<a[y]<<endl;
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
            if(cnt%2)       //ż->��
            {
                if(num>=*it){           //��һ����
                    printf(" %d",*(++it));
                    continue;
                }
                else                   //����
                    ans=*it;
            }
            else            //��->ż
            {
                if(num>=*it)        //(ԭ������λ��+��һ����)/2
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
                else {              //(ԭ������λ��+��һ����)/2
                    multiset<int>::iterator pt=it;
                    it--;           //ָ����һ����С����
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
