//�������Ǵ�˵�еļ��ι�ʽ�⣿����������֮���ǻ�����һ�����Բ�Ľǵ�һ��˰뾶��
//Ȼ�����ڹ�ʽ�ѽ���Ҫ�󾫶Ⱦʹ�h������r�������ҵ�r֮������������������Ŀ�಻��ȡ�
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
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
using namespace std;
double binary(double L1,double L2)
{
    double low = 0.0;
    double high = 0.5*L1;   //�����൱�����Ҫ�ǻ���L1����110msҪ��0.5L1����0ms
    double mid,r;
    while(high - low>eps)
    {
        mid = (low+high)/2;
        r=(4*mid*mid+L1*L1)/(8*mid);
        if(2*r*asin(L1/(2*r))<L2)
            low = mid;
        else high = mid;
    }
    return mid;
}
int main()
{
    double L1,L2,C,n;
    while(scanf("%lf%lf%lf",&L1,&n,&C)!=EOF)
    {
        if(L1<0&&C<0&&n<0) break;
        L2 = (1+n*C)*L1;
        printf("%.3f\n",binary(L1,L2));
    }
return 0;
}
