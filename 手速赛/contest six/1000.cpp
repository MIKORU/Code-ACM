#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // ȡ����ֵ
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility> //pair��
#define LL long long
using namespace std;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a));
#define MAX_N
int reverseBits(int n)
 {
        int t=0;
        int c=0;
        while(c<32)
        {
            t<<=1;
            t|=(n&1);
            n>>=1;
            c++;
        }
        return t;
}

int main()
{
    int  n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",reverseBits(n));
    }
return 0;
}
