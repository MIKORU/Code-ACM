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
#define MAX_N 110
const int INF = 0x3f3f3f3f;
using namespace std;
int n;
int mapn[MAX_N][MAX_N];
int car[MAX_N];
int ans[MAX_N];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(car,0,sizeof(car));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&mapn[i][j]);
                if(mapn[i][j] == 1)
                    car[i] = 1;
                else if(mapn[i][j]==2)
                    car[j] = 1;
                else if(mapn[i][j] == 3){
                    car[i] = 1;car[j] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(!car[i]){
                ans[cnt++]=i;
            }
        }
        printf("%d\n",cnt);
        for(int i=0;i<cnt;i++){
            if(i!=cnt-1)
                printf("%d ",ans[i]);
            else printf("%d\n",ans[i]);
        }
    }
return 0;
}
