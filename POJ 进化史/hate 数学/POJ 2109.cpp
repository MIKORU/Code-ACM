//����kuangbin����Ĵ��룬����������Ǹ߾��ȵģ������double���ˣ���ס���ݷ�Χ�ɡ�
//����pow�Ļ����͸߾��Ⱥͺ�������
//����˼·��
//    1������Ȼ�ģ���Ϊ�������ݺܴ󣬻�ȥ��߾��ȡ�Ȼ��Ӷ��ֲ�����
//    2�������뵽ת����ѧ���㣺ָ�Ի�������double�棬����double ��ȷλֻ��6��7����û��logx Y��ֻ����ת��Ϊ��eΪ�׵Ķ�������lognP=logn/logP�������κ�����
//    ��ȷ�Ȳ�������Ҫ��
//    3����˼·��k^n=p����p^(1/n)=k���Һ�������ֱ����pow(x,y)ȥ��x^y��
//    �ջ񣺹�����һ�»�����������һ��˼ά��
//    ����            ���� (bit)           ��Ч����                   ����ֵ��Χ
//    float            32                     6~7                  10^(-37) ~ 10^38
//    double           64                    15~16                 10^(-307) ~10^308
//    long double      128                   18~19                10^(-4931) ~ 10 ^ 4932
//�򵥷�
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

//Ȼ��Ҳ���Զ��֣��������¡�
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // ȡ����ֵ
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>  //priority_queue<int>
#include <vector>
#include <map>
#include <set>
#include <utility> //pair����� typedef pair<int ,int>P;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a))  //���� memset(a,0x7f,sizeof(a));
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
