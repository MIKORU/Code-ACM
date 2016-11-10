//#include<stdio.h>
//#include<string.h>
//char a[1002],b[1002];
//int sum[1002];
//int max(int a,int b)
//{return a>b?a:b;}
//int main()
//{
//    	freopen("00.txt", "r", stdin);
//    freopen("01.txt","w", stdout);
//
//    int t,m,n,i,j,p,s=0;
//scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%s%s",a,b);
//		if(a[0]=='0'&&b[0]=='0')
//			break;
//        m=strlen(a);
//        n=strlen(b);
//        for(i=m-1;i>=0;i--)
//        {
//            sum[m-1-i]+=a[i]-'0';
//        }
//        for(i=n-1;i>=0;i--)
//        {
//            sum[n-1-i]+=b[i]-'0';
//        }
//        p=max(m,n);
//        for(i=0;i<=p;i++)
//        {
//            if(sum[i]>=10)
//            {
//                sum[i]-=10;
//                sum[i+1]++;
//            }
//        }
//        for(j=1002;;j--)
//        {
//            if(sum[j])
//            {
//                break;
//            }
//        }
//         printf("Case %d:\n%s + %s = ",++s,a,b);
//         for(i=j;i>=0;--i)
//        {
//            printf("%d",sum[i]);
//        }
//        printf("\n");
//		for(i=0;i<1002;i++)
//            sum[i]=0;
//        if(t!=0) putchar('\n');
//    }
//    return 0;
//}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility> //pair类
#define LL long long
using namespace std;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a));
#define MAX_N
string add(string s1,string s2)
{
	if(s1.length()<s2.length())
        swap(s1,s2);
	int i,j;
	for(i=s1.length()-1,j=s2.length()-1;i>=0;i--,j--)
	{
		s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));   //注意细节
		if(s1[i]-'0'>=10)
		{
			s1[i]=char((s1[i]-'0')%10+'0');
			if(i) s1[i-1]++;
			else s1='1'+s1;
		}
	}
	return s1;
}
int main()
{
    int T;
    int t,i=1;
    string a,b,c;
    scanf("%d",&T);
    t = T;
    while(T--)
    {
        cin>>a>>b;
        c = add(a,b);
        cout<<"Case "<<i++<<":"<<endl<<a<<" + "<<b<<" = "<<c<<endl;
        if(i<=t)
            putchar('\n');
    }
    return 0;
}
