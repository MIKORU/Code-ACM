#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility> //pair类
#define LL long long
using namespace std;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a));
#define MAX_N 13
int a[MAX_N];
int main()
{
    int d,s;
    while(scanf("%d%d",&s,&d)!=EOF)
    {
        int sum = a[1] = s;
        int ans=0;
        int cont = 2;
        for(int i=2;i<=12;i++)
        {
            ++cont;
            if(i>5)
            {
                sum-=a[i-5];
                if(sum+s<0)
                    a[i]=s;
                else a[i]=-1*d;
                sum+=a[i];
            }
            else
            {
                if(sum < 0)
                    a[i] = s;
                else
                    a[i] = -1*d;
                sum+=a[i];
                if(cont==4)
                {
                    if(sum+s<0)
                        a[i+1]=s;
                    else a[i+1]=-1*d;
                    sum+=a[i+1];
                    i++;
                }
            }
        }
        for(int i=1;i<=12;i++)
//            ans+=a[i];
//        if(ans<0) printf("Deficit\n");
//        else
            printf("%d\n",a[i]);
    }
return 0;
}
