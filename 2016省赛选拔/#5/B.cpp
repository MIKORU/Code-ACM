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
#define MAXN 100000
const int INF = 0x3f3f3f3f;
using namespace std;
int a[MAXN];
int n;
int main()
{

    while(scanf("%d",&n)!=EOF)
    {
        int ans=0;
        int k=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            if(a[i]==i){
                ans++;
            }
            else if(a[a[i]]==i){
                k=1;
            }
        }
        if(ans == n)
            printf("%d\n",ans);
        else printf("%d\n",k+ans+1);
    }
return 0;
}
