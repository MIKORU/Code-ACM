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
int max_div(int a,int b)
{
    int r;
    while((r = a%b)!=0)
    {
        a = b;
        b = r;
    }
    return b;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int d = max_div(n*m,n+m);
        printf("%d/%d\n",(n*m)/d,(n+m)/d);
    }
return 0;
}
