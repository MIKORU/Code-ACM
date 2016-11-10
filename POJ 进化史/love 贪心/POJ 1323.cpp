//这道题何止是水，简直是太水了，果然是太久没打过题目了，一点感觉都没有，于是再次看了题解，才想出方案，简直是太逊了好嘛！！
//简单来说，就是枚举，反正数据也不大，当别人有比你大的就有可能输。
//两份代码 16ms和32ms

/**测试样例：
2 5
1 7 2 10 9

6 11
62 63 54 66 65 61 57 56 50 53 48

0 0

Case 1: 2
Case 2: 4
**/

//#include <stdio.h>
//#include <algorithm>
//#include <math.h>
//#define MAX_N 55
//using namespace std;
//int a[MAX_N];
//int main()
//{
//    int n,m;
//    int i,j;
//    int s = 1;
//    while(~scanf("%d%d",&m,&n))
//    {
//        if(m==0&&n==0) break;
//        int ans = 0;
//        int maxn = 0;
//        for(i=0;i<n;i++)
//            scanf("%d",&a[i]);
//        for(i=n*m;i>0;i--)
//        {
//            int flag = 0;
//            for(j=0;j<n;j++)
//            {
//                if(a[j]==i)
//                {
//                    flag = 1;
//                    ans++;
//                    maxn=max(ans,maxn);
//                }
//            }
//            if(!flag) ans--;
//        }
//        printf("Case %d: %d\n",s++,maxn);
//    }
//    return 0;
//}
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
int a[100000];
int main()
{
    int n,m;
    int i,j,t;
    int s = 1;
    freopen("新建文本文档.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(~scanf("%d%d",&m,&n))
    {
        if(m==0&&n==0) break;
        int ans = 0;
        int maxn = 0;
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)
        {
            scanf("%d",&t);
            a[t]=1;
        }
        for(i=n*m;i>0;i--)
        {
            int flag = 0;
            if(a[i])
            {
                flag = 1;
                ans++;
                maxn=max(ans,maxn);
            }
            else ans--;
        }
        printf("Case %d: %d\n",s++,maxn);
    }
    return 0;
}


