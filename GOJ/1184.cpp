#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,i;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf",&a,&b);
        for(i=1.000;i>0;i-=0.00001)
            if(a*i+b*log(i)<0.00001)
            {
                printf("%.4f\n",i);
                break;
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
#define Q_CIN ios::sync_with_stdio(false);
#define RE(v) freopen("v.txt","r",stdin);
#define WE(v) freopen("v.txt","w",stdout);



double finds(double le,double ri,double a,double b)
{
    //int le=0,ri=l,mi=(le+ri)/2,ok=1;
     //low=a*le+b*log(le);
    // high=a*ri+b*log(ri);
     double mid=(le+ri)/2.0;
     double midd=a*mid+b*log(mid);
    while(ri-le>0.00001)
    {
        if(midd>0) {ri=mid;mid=(le+ri)/2.0;midd=a*mid+b*log(mid);}
        else if(midd<0) {le=mid;mid=(le+ri)/2.0;midd=a*mid+b*log(mid);}
        else return mid;
    }
    return mid;
    //if(ok) printf("Yes\n");
}



int main()
{
    int t;
    scanf("%d",&t);
    double a,b,s,low,high;
    while(t--)
    {
        scanf("%lf%lf",&a,&b);
        low=0;
        high=1.0;
        s=finds(low,high,a,b);
        printf("%.4f\n",s);
    }

//    mid=(low+high)/2;

//    RE(0)
//    WE(00)
    return 0;
}
*/
