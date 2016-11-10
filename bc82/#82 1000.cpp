#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#define LL long long
using namespace std;
const int INF = 100000005;
LL n;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d",&n);
        int flag = 0;
        //int len = sqrt(n);
        if(n==1||n==4){
            printf("False\n");
            continue;
        }
        if(n&1)
            flag = 1;
        else{
            if(n%4==0)
                flag = 1;
        }
        if(flag) printf("True\n");
        else printf("False\n");
    }
    return 0;
}
