#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>  //priority_queue<int>
#include <vector>
#include <map>
#include <set>
#include <utility> //pair类或者 typedef pair<int ,int>P;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a))  //大数 memset(a,0x7f,sizeof(a));
#define MAXN 301000
const int INF = 0x3f3f3f3f;
using namespace std;

int n,m,k;
set<int> s;
set<int> v[MAXN];
bool vis[MAXN];

int bfs(int a)
{
    int flag = 0;
    vis[a] = true;
    queue<int> q;
    q.push(a);
    vector<int> e;
    while(!q.empty())
    {
        a = q.front();
        q.pop();
        for(set<int>::iterator it = s.begin(); it != s.end(); it++)
        {
            if(*it != a && !vis[*it] && !v[a].count(*it))
            {
                q.push(*it);
                e.push_back(*it);
                vis[*it] = true;
            }
        }
        if(!v[a].count(1)) flag = 1;
        for(int i = 0;i < e.size();i++)
            s.erase(e[i]);
        e.clear();
    }
    return flag;
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&k)){
        int flag = 0;
        s.clear();
        for(int i=1;i<=n;i++)
            v[i].clear();
        int num1 = n-1;
        for(int i = 1;i <= m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].insert(b);
            v[b].insert(a);
            if(a == 1 || b == 1) num1--;
        }
        if(num1 < k)
        {
            printf("NO\n");
            continue;
        }
        for(int i = 2;i <= n;i++)
            s.insert(i);
        CAN(vis,0);
        for(int i = 2;i <= n;i++)
        {
            if(!vis[i])
            {
                if(bfs(i) == 0)
                {
                    flag = 1;
                }
            }
        }
        if(flag == 1){
            printf("NO\n");
            continue;
        }
        if(s.size() > k)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}

