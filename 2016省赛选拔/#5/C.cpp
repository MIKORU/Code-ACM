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
#define MAX_N 1000
const int INF = 0x3f3f3f3f;
using namespace std;
int a[MAX_N];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int Max = -1;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            Max = max(Max,a[i]);
        }
        int k = gcd(a[0],a[1]);
        for(int i=2;i<n;i++){
            k = gcd(k,a[i]);
        }
        printf("%s\n",(Max/k-n)%2?"Alice":"Bob");
    }
return 0;
}
