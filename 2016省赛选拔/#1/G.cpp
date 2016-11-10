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
#define MAX_N 3500
const int INF = 0x3f3f3f3f;
using namespace std;
int n;
int a[MAX_N];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum1+=a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            if(a[i]==a[i-1]){
                a[i]+=1;
            }
            if(a[i]<a[i-1]){
                a[i] += (a[i-1]-a[i])+1;
            }
            sum2+=a[i];
        }
        printf("%d\n",sum2-sum1);

    }
return 0;
}
