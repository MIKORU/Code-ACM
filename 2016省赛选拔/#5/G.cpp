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
#define MAX_N 100010
const int INF = 0x3f3f3f3f;
using namespace std;
LL a[MAX_N];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++){
            scanf("%I64d",&a[i]);
        }
        sort(a,a+n);
        LL cnt = 0;
        for(int i=0;i<n;i++){
            cnt+=a[i];
        }
        LL ans;
        if(cnt%(n-1)){
            ans = max(a[n-1],cnt/(n-1)+1);
        }
        else{
            ans = max(a[n-1],cnt/(n-1));
        }
        printf("%I64d\n",ans);
    }
return 0;
}
