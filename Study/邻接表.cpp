#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_V = 100000;
////边上有属性的情况
//struct edge{
// int to,cost;
//};
//vector<edge>G[MAX_V];
//////一般情况
////vector<int> G[MAX_V];
//
//int main()
//{
//    int V,E;
//    cin>>V>>E;
//    for(int i=0;i<E;i++)
//    {
//        int s,t,c;
//        cin>>s>>t;
//        G[s].push_back(t);  //在vector类中作用为在vector尾部加入一个数据。
//        //无向图则需再从t向s连边
//    }
//    return 0;
//}
//方式二
//struct vertex{
//vector <vertex*> edge;
//};
//vertex G[MAX_V];
//int main()
//{
//    int V,E;
//    cin>>V>>E;
//    for(int i=0;i<E;i++)
//    {
//        int s,t;
//        cin>>s>>t;
//        G[s].edge.push_back(&G[t]);
//        //G[t].edge.push_back(&G[s]);
//    }
//    return 0;
//}
//题目 have problems
//vector<int >G[MAX_V];
//int V;
//int color[MAX_V];
//bool dfs(int v,int c)
//{
//    color[v] = c;
//    for(int i=0;i<G[v].size();i++)
//    {
//        if(color[G[v][i]]==c)
//            return false;
//        if(color[G[v][i]]==0&&!dfs(G[v][i],-c))
//            return false;
//    }
//    return true;
//}
//void solve()
//{
//    for(int i=0;i<V;i++)
//    {
//        if(color[i]==0)
//            if(!dfs(i,1))
//            {
//                cout<<"No\n";
//                return ;
//            }
//    }
//    cout<<"Yes\n";
//}
//void init()
//{
//    memset(color,0,sizeof(color));
//}
//int main()
//{
//    while(cin>>V)
//    {
//        solve();
//    }
//    return 0;
//}
const int MAX_E = 10000;
const int INF = 0x3f3f3f3f;
struct edge{
int from,to,cost;
};
edge es[MAX_E];
int d[MAX_V];
int V,E;
void shortest_path(int s)
{
    for(int i=0;i<V;i++)
        d[i]=INF;
    d[s] = 0;
    while(true)
    {
        bool update = false;
        for(int i=0;i<E;i++)
        {
            edge e = es[i];
            if(d[e.from]!= INF && d[e.to]>d[e.from]+e.cost)
            {
                d[e.to] = d[e.from]+e.cost;
                update = true;
            }
        }
        if(!update)
            break;
    }
}
