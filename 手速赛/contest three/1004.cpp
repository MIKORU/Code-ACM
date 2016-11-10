#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // È¡¾ø¶ÔÖµ //
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility> //pair<int int >a[?]
using namespace std;
#define N
int main()
{
    long long  A[3];
    long long  a,b,c;
    long long s;
    while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
    {
        A[0]=a;
        A[1]=b;
        A[2]=c;
        sort(A,A+3);
        s = A[0];
        A[1]-=A[0];
        A[2]-=A[0];
//        printf("%lld %lld\n",A[1],A[2]);
        while(A[2]>=2&&A[1]>=1)
                {
                    s++;
                    A[2]-=2;
                    A[1]-=1;
                }
        printf("%lld\n",s);
    }
return 0;
}
