//这道题就是传说中的几何公式题？？哈哈，总之就是弧长的一半等于圆心角的一半乘半径。
//然后由于公式难解又要求精度就从h出发找r，二分找到r之后，算出弧长与给出的题目相不相等。
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
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
using namespace std;
double binary(double L1,double L2)
{
    double low = 0.0;
    double high = 0.5*L1;   //这里相当的玄妙，要是换成L1就是110ms要是0.5L1就是0ms
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
