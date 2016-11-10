//#include <stdio.h>
//#include <algorithm>
//#include <math.h>
//using namespace std;
//long long A[100000000];
//int cmp(int a,int b){
//    if(abs(a)>abs(b))
//        return a>b;
//    else return a<b;
//}
//int main()
//{
//    int c = 1,T;
//    long long n,a,b;
//    long long ans1,ans2;
//    scanf("%d",&T);
//    while(T--){
//        ans1 = ans2 = 0;
//        scanf("%lld%lld%lld",&n,&a,&b);
//        for(int i=0;i<n;i++){
//            scanf("%lld",&A[i]);
//        }
//        if(a>0&&b>0){
//            sort(A,A+n);
//            ans1 = b*A[n-1];
//            ans2 = b*A[n-2];
//            sort(A,A+n,cmp);
//            ans1 += a*A[1]*A[1];
//            ans2 += a*A[0]*A[0];
//        }
//        else{
//            if(a<0&&b>0){
//                sort(A,A+n);
//                ans1 = b*A[0];
//                sort(A,A+n,cmp);
//                ans1 += a*A[0]*A[0];
//            }
//            if(a>0&&b<0){
//                sort(A,A+n);
//                ans1 = b*A[n-1];
//                sort(A,A+n,cmp);
//                ans1 += a*A[n-1]*A[n-1];
//            }
//            if(a<0&&b<0){
//                sort(A,A+n);
//                ans1 = b*A[0];
//                sort(A,A+n,cmp);
//                ans1 += a*A[n-1]*A[n-1];
//            }
//        }
//        printf("Case #%d: %lld\n",c++,max(ans1,ans2));
//    }
//    return 0;
//}
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
const int INF=0x3f3f3f3f;
using namespace std;
int d[5000005];
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        int cnt=1;
        while(t--)
        {
            int a,b,n,mid=INF,maxn=-INF,minn=INF;
            long long sum=0,sum1,sum2;
            scanf("%d%d%d",&n,&a,&b);
            for(int i=0;i<n;i++)
            {
                scanf("%d",&d[i]);
                mid=min(mid,abs(d[i]));
            }
            sort(d,d+n);
            if(a>=0&&b>=0)
            {
                sum1=1LL*a*d[n-1]*d[n-1]+1LL*b*d[n-2];
                sum2=1LL*a*d[n-2]*d[n-2]+1LL*b*d[n-1];
                sum=max(sum1,sum2);
            }
            if(a>=0&&b<0)
            {
                sum=1LL*a*d[n-1]*d[n-1]+1LL*b*d[0];
            }
            if(a<0&&b>0)
            {
                sum=1LL*a*mid*mid;
                if(mid==d[n-1])
                    sum+=1LL*b*d[n-2];
                else
                    sum+=1LL*b*d[n-1];
            }
            if(a<0&&b<0)
            {
                sum=1LL*a*mid*mid;
                if(mid==d[0])
                    sum+=1LL*b*d[1];
                else
                    sum+=1LL*b*d[0];
            }
            printf("Case #%d: %lld\n",cnt++,sum);
        }
    }
    return 0;
}
