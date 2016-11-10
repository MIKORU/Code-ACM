#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int m,n,t,s,l,i=1;
    scanf("%d",&t);
    l=t;
    while(t--)
    {
        scanf("%d%d",&m,&n);
        if(m>n)
            s=(m-1)+(n-1)*m;
        else
            s=(m-1)*n+(n-1);
        printf("Case #%d: %d\n",i++,s);
    }
    return 0;
}
