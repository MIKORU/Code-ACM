//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h> // 取绝对值
//#include <iostream>
//#include <algorithm>
//#include <stack>
//#include <map>
//#include <set>
//#include <utility> //pair类
//#define LL long long
//using namespace std;
//#define LL long long
//#define CAN(a,b) memset(a,b,sizeof(a));
//#define MAX_N 1000005
//struct node
//{
//    int x;
//    int y;
//} a[MAX_N];
//bool cmp(node a, node b)
//{
//    if(a.x == b.x)
//        return true;
//    return false;
//}
//int main()
//{
//    int T;
//    int n, m;
//    scanf("%d",&T);
//    while(T--)
//    {
//        int ans = 0;
//        int cur = 0;
//        scanf("%d",&n);
//        for(int i=0;i<n;i++)
//            scanf("%d%d",&a[i].x,&a[i].y);
//        scanf("%d",&m);
//        for(int i=n;i<m+n;i++)
//            scanf("%d%d",&a[i].x,&a[i].y);
//        sort(a,a+n+m,cmp);
//        for(int i=0;i<n+m;i++)
//        {
//            if(a[i].x>cur)
//                cur = a[i].x;
//            if(cur <= a[i].y)
//            {
//                ans+=a[i].y-cur+1;
//                cur=a[i].y+1;
//            }
//        }
//        printf("%d\n",ans);
//    }
//    return 0;
//}

//#include <cstdio>
//#include<cstdlib>
//#include<cstring>
//#include<iostream>
//#define N 1000+5
//#define maxx(a,b) a>b?a:b
//using namespace std;
//int dp[N][N];
//char str1[N],str2[N];
//int LCSL(int len1,int len2)
//{
//    int i,j;
//    int len=maxx(len1,len2);
//    for(i=0;i<=len;i++)
//        dp[i][0]=0;dp[0][i]=0;
//    for(i=1;i<=len1;i++)
//        for(j=1;j<=len2;j++)
//        {
//            if(str1[i-1]==str2[j-1])
//                dp[i][j]=dp[i-1][j-1]+1;
//            else
//                dp[i][j]=maxx(dp[i-1][j],dp[i][j-1]);
//        }
//    return dp[len1][len2];
//}
//int main()
//{
//    int n,m;
//    int ans;
//    while(scanf("%d%d%*c",&n,&m)!=EOF)
//    {
//        ans=0;
//        for(int j=0;i<n;i++)
//        {
//            for(int i=0;i<m;i++)
//            {
//                scanf("%c%*c",&str1[i]);
//                scanf("%c%*c",&str2[i]);
//            }
//            int ans=LCSL(m,m)+1;
//        }
//        printf("%d\n",ans);
//    }
//    return 0;
//}
/*
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
#define MAX_N 1005
int a[MAX_N];
int main()
{
    int n;
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        int maxn=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n);
        for(i=n-1,j=1;i>=1;i--,j++)
        {
            a[i]=a[i]+j*5;
            maxn=max(maxn,a[i]);
        }
        printf("%d\n",maxn);
    }
return 0;
}
*/
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
#define CAN(a,b) memset(a,b,sizeof(a))
#define MAX_N 100005
int a[MAX_N];
int main()
{
    int T;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        CAN(a,0);
        int ans=0;
        int sum2=0;
        scanf("%d",&n);
        scanf("%d",&a[0]);
        int sum1=a[0];
        for(int i=1;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum2+=a[i];
            if(sum2>sum1)
            {
                sum1+=sum2;
                sum2=0;
                ans++;
            }
        }
        printf("%d\n",ans+1);
    }
return 0;
}
