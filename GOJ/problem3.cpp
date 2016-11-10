/*
    poj 1064 Cable master

    解题思路:
        1、二分法枚举所有可能的长度，求得最大长度值 -- 所谓可能长度，即该长度能够产生多于或等于K份
        【二分搜索，这里是找出满足条件的最大的那个。
        而这里是用二分搜索来不断缩小区间的方法来加速枚举。】

    坑点：
        1、精度（最坑没有之一）
        【附上 BT测试数据】
        4 2540
        8.02
        7.43
        4.57
        5.39

        =>0.01

        4 2542
        8.02
        7.43
        4.57
        5.39

        =>0.00

        解决精度问题，可以将输入数据乘以100换算成整数进行计算。

        2、不一定会选择全部的辣条

        2 2
        1.02
        2.33

        => 1.16

        3、本次数据采用POJ discuss内某大牛提供的测试数据，十分强悍。（各种trick）
*/

#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=10010;
double L[maxn];
double eps=1e-5;
int main()
{
//    freopen("00.txt","r",stdin);
//    freopen("01.txt","w",stdout);
        int n, k;
        while(~scanf("%d %d", &n, &k))
        {
            double maxvalue=0;
            for(int i=0;i<n;i++)
            {
                scanf("%lf", L+i);
                if(L[i]>maxvalue)
                    maxvalue=L[i];
            }
            double lp=0, rp=maxvalue;
            while(rp-lp>eps)
            {
                double mid=(rp+lp)/2;
                int sum=0;
                for(int i=0;i<n;i++)
                    sum+=L[i]/mid;
                if(sum>=k)
                    lp=mid;
                else
                    rp=mid;
            }
            printf("%.2f\n", int(rp*100)*0.01);   //精度处理
        }
    return 0;
}
