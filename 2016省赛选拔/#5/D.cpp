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
#define MAXN 105
const int INF = 0x3f3f3f3f;
using namespace std;
int num[MAXN];
int ans[MAXN];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int maxn = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        sort(num,num+n);
        swap(num[0],num[n-1]);
        for(int i=0;i<n-1;i++){
            printf("%d ",num[i]);
        }
        printf("%d\n",num[n-1]);
    }
return 0;
}
