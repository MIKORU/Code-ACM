//这是比赛题，还是作死的我最讨厌的英文题，题目大意就是有n头奶牛，要在喂奶截止时间前给他喂奶并得到相应的含量的牛奶。
//一开始的想法就是挑选截止日期的最大产奶量的那头牛喂养，后来果不其然的WA了。
//空闲的时间也可以给奶牛喂奶啥的....bug不要太多。
//于是改来改去了，期间又WA了几发，总算是A掉了，但是代码也是要多搓有多搓，估计除了我自己没人看得懂。
//所以后来选用了优先队列，STL的东西用顺手了还是蛮好用的。还用了pair类。
//思路从截止日期最大的倒着推回来，每次选择最优。优先队列访问顶元素得到最优解加起来。
/**
测试实例：
4
10 3
7 5
8 1
2 1
10
4 4
2 1
2 8
1 2
10 5
10 3
9 5
10 1
3 7
8 4

25
52
**/
#include<cstdio>
#include<queue>
#include<algorithm>
#define MAXN 10000
using namespace std;
typedef pair<int ,int> P;
priority_queue<int> q;
int n,ans;
P a[MAXN+10];
int main()
{
	while(~scanf("%d",&n))
	{
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i].second,&a[i].first);
        sort(a+1,a+1+n);   //sort对pair先排first（本题中的d）从小到大，再排second（本题中g）从小到大
        for(int t=a[n].first,j=n;t>=1;t--)   //倒着选
        {
            for(;j>=1&&t<=a[j].first;j--)  //将当前所有解入队列，排过序。
                q.push(a[j].second);
            if(!q.empty())
            {
                ans+=q.top();  //选择最优解
                q.pop();  //已选择则扔出去233333，留下的而下一次选择时候就一定在截止时间内了。
            }
        }
        printf("%d\n",ans);
        }
	return 0;
}
