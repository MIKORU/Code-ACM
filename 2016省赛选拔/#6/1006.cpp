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
#define M 500010
using namespace std;
int main()
{
    int T;
	long long n;
	scanf("%d",&T);
	while(T--){
        scanf("%lld",&n);
        if(n&1)
            printf("1\n");
        else printf("0\n");
	}
	return 0;
}
