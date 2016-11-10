//贪心还是很不熟练地看别人的代码写完的TT要成为大牛还是远得很呢！！继续加油啊！！
//解题思路大概就是从小排（这个很重要，一开始就是排反了，然后用cmo随便长度或者重量的排序，选择最小的开始）直到
//所有比他weight大的，没有符合条件的了。然后再次访问，用used标记有没有用过。和活动顺序排序有点类似。


/**测试样例：
3
5
4 9 5 2 2 1 3 5 1 4
3
2 2 1 1 2 2
3
1 3 2 2 3 1

2
1
3
**/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX_N 5000+10
int used[MAX_N];
struct node
{
    int len;
    int wei;
}a[MAX_N];
int cmp(node a,node b)
{
    if(a.len==b.len)
        return a.wei<b.wei;
    return a.len<b.len;
}
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        int ans = 0;
        memset(used,0,sizeof(used));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i].len,&a[i].wei);
        sort(a,a+n,cmp);
        for(int j=0;j<n;j++)
        {
            if(used[j]) continue;
            int weimax = a[j].wei;
            ans++;
            for(int i=j+1;i<n;i++)
            {
                if(!used[i]&&a[i].wei>=weimax)
                {
                    used[i]=1;
                    weimax = a[i].wei;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
