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
#define N 100010
const int INF = 0x3f3f3f3f;
using namespace std;
struct node
{
    char s[30];
}a[N];
string aa,bb;
int cmp(const node& a,const node& b)
{
    aa=a.s;
    aa+=b.s;
    bb=b.s;
    bb+=a.s;
    return aa<bb;
}
int main()
{
    int i,j,k,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%s",a[i].s);
        sort(a,a+n,cmp);
        k=0;
        for(i=0; i<n; i++)
        {
            for(j=0; a[i].s[j]; j++)
            {
                printf("%c",a[i].s[j]);
                k++;
                if(k>=1000)
                {
                    k=0;
                    printf("\n");
                }
            }
        }
        if(k)printf("\n");
    }
    return 0;
}
