#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility>//pair类
using namespace std;
int max_div(int a,int b)
{
    int r;
    while((r = a%b)!=0)
    {
        a = b;
        b = r;
    }
    return b;
}
int main()
{
      int T,a,m,i;
      scanf("%d",&T);
      while(T--)
      {
            scanf("%d%d",&a,&m);
            if(m==1)
            {
                printf("1\n");
                continue;
            }
            if(max_div(a,m)!=1)
            {
                printf("Not Exist\n");
                continue;
            }
            for(i=1;;i++)
            {
                 if(a*i%m==1)
                    break;
            }
            printf("%d\n",i);
       }
       return 0;
}
