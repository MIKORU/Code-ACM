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
int main()
{
    double v1,v2,d;
    while(scanf("%lf%lf%lf",&v1,&v2,&d)!=EOF)
    {
        d = 1000*d;
        double ans1,ans2,s;
        if(v1==0||d==0) printf("Not sure!\n");
        if(v2==0)
        {
            printf("0 %d\n",(int)(d/v1+0.5));
            continue;
        }
        if(v1>v2)
        {
            ans1=d/(sin(acos(v2/v1))*v1);
            printf("0 %ds\n",(int)(ans1+0.5));
        }
        else
        {
            s =sqrt((v2*d/v1)*(v2*d/v1)-d*d);
            ans2 = d/v1;
            printf("%d %ds\n",(int)(s+0.5),(int)(ans2+0.5));
        }
    }
return 0;
}
