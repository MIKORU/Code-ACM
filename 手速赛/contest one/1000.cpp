#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // È¡¾ø¶ÔÖµ //
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define N
int main()
{
    int k;
    long long i;
    double s;
    while(scanf("%d",&k)!=EOF)
    {
        s=0;
        for(i=1;;i++)
        {
            s+=(double) 1/i;
            if(s>k)
                break;
        }
    printf("n=%lld\n",i);
    }

return 0;
}
