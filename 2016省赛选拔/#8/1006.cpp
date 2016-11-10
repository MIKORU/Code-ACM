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
char a[1500];
int f[1500][1500];
int length;
int main()
{
    while(scanf("%s",a)!=EOF)
    {
        CAN(f,0);
        length = strlen(a);
        for(int i=length -1;i>=0;i--){
            for(int j=i+1;j<length ;j++){
                if(a[i] == a[j])
                    f[i][j] = f[i+1][j-1];
                else
                    f[i][j] = min(f[i][j-1],f[i+1][j])+1;
            }
        }
        int ans = f[0][length-1];
        if(ans==1){
            printf("Yes\n");
        }
        else if(ans==0){
            printf("Heheda\n");
            break;
        }
        else printf("No\n");
    }
return 0;
}
