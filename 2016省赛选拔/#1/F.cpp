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
#define MAX_N
const int INF = 0x3f3f3f3f;
using namespace std;
int k,n,w;
int main()
{
    while(scanf("%d%d%d",&k,&n,&w)!=EOF)
    {
        int mon=(w*(w+1)*k)/2;
        if(mon > n)
            printf("%d\n",mon-n);
        else printf("0\n");
    }
return 0;
}
