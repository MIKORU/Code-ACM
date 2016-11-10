



/**
#include <iostream>
#include <string.h>
using namespace std;
//dp[i][0]������Ϊi����49����
//dp[i][1]������Ϊi����49�����λΪ9����
//dp[i][2]������Ϊi����49����
long long dp[22][3];
int bit[21];
long long n;

void init()
{
    dp[0][0]=1,dp[0][1]=0,dp[0][2]=0;
    for(int i=1;i<=21;i++)
    {
        dp[i][0]=dp[i-1][0]*10-dp[i-1][1];//dp[i][0]��λ����һ�����ֶ����ԣ����ǻ����49XXX�������Ҫ��ȥ
        dp[i][1]=dp[i-1][0];//�ڲ���49������¸�λ��9
        dp[i][2]=dp[i-1][2]*10+dp[i-1][1];//�ں���49������¸�λ���һλ���߲���49����λ��9����ǰ�����λ����4�Ϳ�����
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
    for(int i=len;i>=1;i--)//ÿ��ȷ��һλ
    {
        ans+=dp[i-1][2]*bit[i];//��λ�к���49����λ���һ��1,2,3....bit[i]�����ԣ�bit[i]�Ǵ����м������֣�����bit[i]=5,��ô������������֣�0,1,2,3,4����5С��
        if(!has)
        {
            if(bit[i]>4)
                ans+=dp[i-1][1];//��λ�и�λ��9��ǰ�����4�Ϳ�����
        }
        else
            ans+=(dp[i-1][0])*bit[i];//�����49�������ѡ�ˣ����� 495��ʱ����490 491 492 493 494
            //������仰��������һ����ʱ�䡣Ϊʲô��д��d[i-1][0]+dp[i-1][2]��*bit[i]�أ�ǰ���Ѿ����ֹ�49
            //��ô��λ����ѡ�񶼿��ԣ�dp[i-1][0]����Щ��λ������49�ģ�dp[i-1][2]����Щ��λ����49�ģ�����˵Ӧ��
            //���ϰ���BUT��������ע��ѭ������ĵ�һ��ans+=dp[i-1][2]*bit[i]; ǰ���Ѿ�������dp[i-1][2]��λ��
            //49������ˣ�������������........
        if(bit[i+1]==4&&bit[i]==9)
           has=true;
    }
    if(has)
        ans++;
    return ans;
}

//��491Ϊ������������б�400С�������ж��ٷ�������ģ�Ȼ��4��һλȷ���Ժ��������б�490С����������б�491С
//i=3 ����� 049 149 249 349
//i=2 ����� 449
//i=1 ����� 490

//�������49 ���������491
**/




















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
LL dp[25][3];
int A[25];

//(0,a]��Χ���ж��ٸ�������
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
   //������
   if(flag) ans++;
   return ans;
}

//dp[i][0]:����<=i�Ĳ���49�����ĸ���
//dp[i][1]:����Ϊi,�����λ����9�Ĳ���49�����ĸ���
//dp[i][2]:����<=i�ĺ���49��������
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
