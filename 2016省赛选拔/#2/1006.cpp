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
#define MAX_N 10000005
const int INF = 0x3f3f3f3f;
using namespace std;
int N;
char S[MAX_N];
string a;
string b;
int main()
{
    while(scanf("%d",&N)!=EOF)
    {
        long long ans = 0;
        b.clear();
        scanf("%s",S);
        for(int i=0;i<N;i++){
            b+=('a'+i);
        }
        int length = strlen(S);
        for(int i=0;i<length-N+1;i++){
            a.clear();
            for(int j=0;j<N;j++){
                a+=S[i+j];
            }
            //cout<<"a="<<a<<endl;
            sort(a.begin(),a.end());
            if(a==b){
                ans++;
            }
        }
        printf("%lld\n",ans);
    }
return 0;
}
