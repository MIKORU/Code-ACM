//�����ûʲô��˵����УOJ��������Ŀ��࣬�������Բ����x��ĵ㣬Ȼ����̰�����ص����֡���ϸ�����롣�е�����meetingϵ�С�

/**����������
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

bool cmp(node a,node b)//�������С����ǰ�棬��ͬʱ���ұߴ����ǰ�档
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
      if(fabs(y) > R) //�޽�
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
