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
#define M 500010
using namespace std;
int dp[M][2],a[M];
int main()
{
	int n,T;
	scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=2;i<=n;i++) {
            dp[i][1]=max(dp[i-1][0]+abs(a[i]-1),dp[i-1][1]+abs(a[i]-a[i-1]));
        }
        printf("%d\n",dp[n][1]);
	}
	return 0;
}
