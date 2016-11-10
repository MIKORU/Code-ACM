



/**
#include <iostream>
#include <string.h>
using namespace std;
//dp[i][0]代表长度为i不含49的数
//dp[i][1]代表长度为i不含49且最高位为9的数
//dp[i][2]代表长度为i含有49的数
long long dp[22][3];
int bit[21];
long long n;

void init()
{
    dp[0][0]=1,dp[0][1]=0,dp[0][2]=0;
    for(int i=1;i<=21;i++)
    {
        dp[i][0]=dp[i-1][0]*10-dp[i-1][1];//dp[i][0]高位随便加一个数字都可以，但是会出现49XXX的情况，要减去
        dp[i][1]=dp[i-1][0];//在不含49的情况下高位加9
        dp[i][2]=dp[i-1][2]*10+dp[i-1][1];//在含有49的情况下高位随便一位或者不含49但高位是9，在前面最高位加上4就可以了
    }
}

long long cal(long long n)
{
    int len=0;
    while(n)
    {
        bit[++len]=n%10;
        n/=10;
    }
    long long ans=0;
    bit[len+1]=0;
    bool has=false;
    for(int i=len;i>=1;i--)//每次确定一位
    {
        ans+=dp[i-1][2]*bit[i];//低位中含有49，高位随便一个1,2,3....bit[i]都可以，bit[i]是代表有几个数字，比如bit[i]=5,那么代表有五个数字，0,1,2,3,4，比5小。
        if(!has)
        {
            if(bit[i]>4)
                ans+=dp[i-1][1];//低位中高位是9，前面加上4就可以了
        }
        else
            ans+=(dp[i-1][0])*bit[i];//如果有49，就随便选了，比如 495的时候，有490 491 492 493 494
            //上面这句话困扰了我一天多的时间。为什么不写（d[i-1][0]+dp[i-1][2]）*bit[i]呢，前面已经出现过49
            //那么低位任意选择都可以，dp[i-1][0]是那些低位不出现49的，dp[i-1][2]是那些低位出现49的，按理说应该
            //加上啊，BUT！！！清注意循环里面的第一句ans+=dp[i-1][2]*bit[i]; 前面已经加上了dp[i-1][2]低位有
            //49的情况了，哎，欲哭无泪........
        if(bit[i+1]==4&&bit[i]==9)
           has=true;
    }
    if(has)
        ans++;
    return ans;
}

//以491为例，先求出所有比400小的数中有多少符合题意的，然后4这一位确定以后，再求所有比490小，再求出所有比491小
//i=3 求出数 049 149 249 349
//i=2 求出数 449
//i=1 求出数 490

//自身包含49 所以求出数491
**/




















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
#define MAX_N
LL dp[25][3];
int A[25];

//(0,a]范围内有多少个吉利数
LL calc(LL a)
{
   int m = 0;
   LL ans = 0;
   bool flag = false;
   while(a)
   {
      A[++m] = a%10;
      a/=10;
   }
   A[m+1]=A[m+2] = 0;
   for(int i=m+1;i>=2;i--)
   {
      ans += dp[i-1][2] * A[i+1];
      if(flag)
      {
         ans += dp[i-1][0] * A[i+1];
      }
      else
      {
         if(A[i]>2) ans += dp[i-1][1];
         if(A[i+2] == 2 && A[i+1] == 3 && A[i] == 3) flag = true;
      }
   }
   //数本身
   if(flag) ans++;
   return ans;
}

//dp[i][0]:长度<=i的不含49的数的个数
//dp[i][1]:长度为i,且最高位含有9的不含49的数的个数
//dp[i][2]:长度<=i的含有49的数个数
void init()
{
   CAN(dp,0);
   dp[0][0] = 1;
   for(int i=1;i<=22;i++)
   {
      dp[i][0] = dp[i-1][0]*10 - dp[i-1][1];
      dp[i][1] = dp[i-1][0];
      dp[i][2] = dp[i-1][2] * 10 + dp[i-1][1];
   }
}

int main()
{
    LL n;
    int T;
    init();
    scanf("%d",&T);
    while(T--)
    {

        scanf("%lld",&n);
        LL ans = calc(n);
        printf("%lld\n",ans);

    }
return 0;
}
