//借了kuangbin大神的代码，本来这道题是高精度的，愣是用double过了，记住数据范围吧。
//不用pow的话，就高精度和函数来表达。
//三种思路：
//    1、很自然的，因为觉得数据很大，会去想高精度。然后加二分猜数。
//    2、于是想到转换数学运算：指对互化。用double存，但是double 精确位只有6—7。而没有logx Y，只有先转化为以e为底的对数。用lognP=logn/logP。用两次函数，
//    精确度不能满足要求。
//    3、换思路：k^n=p，则p^(1/n)=k。且函数可以直接用pow(x,y)去求x^y。
//    收获：巩固了一下基础。启发了一下思维。
//    类型            长度 (bit)           有效数字                   绝对值范围
//    float            32                     6~7                  10^(-37) ~ 10^38
//    double           64                    15~16                 10^(-307) ~10^308
//    long double      128                   18~19                10^(-4931) ~ 10 ^ 4932
//简单法
#include<stdio.h>
#include<cmath>
int main()
{
    double n,p;
    while(scanf("%lf%lf",&n,&p)!=EOF)
    {
        printf("%.0f\n",pow(p,1/n));
    }
    return 0;
}

//然而也可以二分，试着敲下。
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>  //priority_queue<int>
#include <vector>
#include <map>
#include <set>
#include <utility> //pair类或者 typedef pair<int ,int>P;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a))  //大数 memset(a,0x7f,sizeof(a));
#define MAX_N
const int INF = 0x3f3f3f3f;
using namespace std;
LL binary(double n,double p)
{
    LL right,left,mid;
    double ans;
    right = 10000000002;
    left = 0;
    while(left<=right)
    {
        mid = (left+right)/2;
        ans = pow(mid,n);
        if(ans == p)
            return mid;
        else
        {
            if(ans<p)
                left = mid+1;
            else right = mid;
        }
    }
}
int main()
{
    double n,p;
    while(scanf("%lf%lf",&n,&p)!=EOF)
    {
        printf("%lld\n",binary(n,p));
    }
return 0;
}
