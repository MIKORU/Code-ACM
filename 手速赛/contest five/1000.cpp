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
#define MAX_N 50005
using namespace std;
#define  mod  10001 ;

int main ()
{
    int x[MAX_N];
    int n,a,b,flag;
    int s;
    while (scanf ("%d",&n)!=EOF)
    {
        for (int i=1;i<2*n;i+=2)
            scanf ("%d",&x[i]);
        for (a=0;a<=10000;a++)
        {
            for (b=0;b<=10000;b++){

                s=(a*x[1]+b)%mod;
                s=(a*s+b)%mod;
                if (s==x[3])
                    break ;
            }
            flag=0;
            for (int i=2;i<=2*n;i++)
            {
                s =(a*x[i-1]+b)%mod;
                if (i%2&&s!=x[i])
                {
                    flag=1;
                    break ;
                }
                x[i]=s;
            }
            if (!flag)
                break ;
        }
        for (int i=2;i<=2*n;i+=2)
            printf ("%d\n",x[i]);
    }
    return 0;
}
































int main(){
  int T;
  int x[MAXD];
  scanf("%d",&T);
  for(int i = 1 ; i < 2 * T ; i+= 2)
    scanf("%d",&x[i]);
  int ok,a,b;
  for(i = 0 ; i <= 10000 ; i++){
    for(j = 0; j <= 10000 ; j++){
       ok = 1;
       for(int i = 2 ; i <= 2 * T ; i++){
         if(i & 1){
          if(x[i] != ((a * x[i - 1] + b) % 10001)){
            ok = 0;
            break;
          }
         }
         else{
          x[i] = (a * x[i - 1] + b) % 10001;
         }
       }
       if(ok)
        break;
    }
    if(ok)
      break;
  }
  for(int i = 2 ; i <= 2 * T ; i+= 2)
  printf("%d\n",x[i]);
  return 0;
}
