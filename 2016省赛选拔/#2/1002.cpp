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
#define MAX_N 2005
const int INF = 0x3f3f3f3f;
using namespace std;
int N;
char S[MAX_N+1];
void solve(){
    int a = 0;
    int b = N-1;
    while(a<=b){
        bool left = false;
        for(int i=0;a+i<=b;i++){
            if(S[a+i] < S[b-i]){
                left = true;
                break;
            }
            else if(S[a+i]>S[b-i]){
                left = false;
                break;
            }
        }
        if(left)
            putchar(S[a++]);
        else putchar(S[b--]);
    }
    putchar('\n');
}
int main()
{
    while(~scanf("%d",&N))
    {
        scanf("%s",S);
        solve();
    }
    return 0;
}
