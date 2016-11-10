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
int main()
{
    int p,e,i,d;
    int cases=1;
    while(scanf("%d%d%d%d",&p,&e,&i,&d))
    {
        if(p==-1&&e==-1&&i==-1&&d==-1)
            break;
        int sum=(1288*(i)+5544*(p)+14421*(e))%(21252);
        if(sum-d>0)
            printf("Case %d: the next triple peak occurs in %d days.\n",cases++,sum-d);
        else
            printf("Case %d: the next triple peak occurs in %d days.\n",cases++,21252+sum-d);
        }
return 0;
}
