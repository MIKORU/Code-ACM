//这道题没什么好说，和校OJ上两道题目差不多，求出各个圆交于x轴的点，然后用贪心算重叠部分。详细见代码。有点类似meeting系列。

/**测试样例：
3 2
1 2
-3 1
2 1

1 2
0 2

0 0

Case 1: 2
Case 2: 1
**/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;
#define  MAX_N 1010

struct node
{
  double l,r;
}a[MAX_N];

bool cmp(node a,node b)//排序，左边小的排前面，相同时，右边大的排前面。
{
  if(a.r<b.r)
    return true;
  else if(a.r==b.r)
  {
    if(a.l>b.l)
      return true;
    return false;
  }
  return false;
}


int main()
{
  double x,y;
  int N,R;
  int count=1;
//      freopen("00.txt","r",stdin);
//    freopen("01.txt","w",stdout);
  while(scanf("%d%d",&N,&R)!=EOF)
  {
      bool flag=1;
      int ans=1;
    if(N==0&&R==0) break;

    for(int i=1;i<=N;i++)
    {
      scanf("%lf%lf",&x,&y);
      if(fabs(y) > R) //无解
        flag=0;
      else if(flag)
      {
        a[i].l=x-sqrt((double)R*R - (double)y*y);
        a[i].r=x+sqrt((double)R*R - (double)y*y);
      }
    }
    if(!flag)
    {
      printf("Case %d: -1\n",count++);
      continue;
    }
    sort(a+1,a+1+N,cmp);
    double t=a[1].r;
    for(int i=2;i<=N;i++)
    {
      if(t<a[i].l)
      {
        ans++;
        t=a[i].r;
      }
    }
    printf("Case %d: %d\n",count++,ans);
  }
  return 0;
}
