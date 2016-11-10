#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // ȡ����ֵ
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <queue>  //priority_queue<int>
#include <utility> //pair����� typedef pair<int ,int>P;
#define LL long long
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a))
#define MAX_N 10005
const int INF = 0x3f3f3f3f;
using namespace std;
int pair[MAX_N];
int rank[MAX_N];
//��ʼ��n��Ԫ��
void init(int n)
{
    for(int i = 0;i<n;i++)
    {
        par[i] = i;  //����
        rank[i]=0;  //rank��ʾ�߶�
    }
}
//��ѯ���ĸ�
int find(int x)
{
    if(par[x] == x)   //�����
        return x;
    else return par[x] = find[par[x]];
}
//�ϲ�x,y���ڵļ���
void unite(int x,int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return ;
    // else par[x] = y;�����ֲ���Ҫrank��
    if(rank[x]<rank[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if(rank[x] == rank[y])
            rank[x]++;
    }
}
// �ж�x,y�Ƿ�����һ������
bool same(int x,int y)
{
    return find(x)==find(y);
}


//ʳ�����ǵ���
int N,K;
int T[MAX_N],X[MAX_N],Y[MAX_N];
void solve()
{
    init(N*3);
    int ans = 0;
    for(int i = 0; i < K ; i++)
    {
        int t = T[i];
        int x = X[i]-1,y = Y[i]-1;
        if(x<0||N<=x||y<0||N<=y)
        {
            ans++;
            continue;
        }
    }
    if(t == 1)
    {
        if(same(x,y+N)||same(x,y+2*N))
            ans++;
        else
        {
            unite(x,y);
            unite(x+N,y+N);
            unite(x+N*2,y+N*2);
        }
    }
    else
    {
        if(same(x,y)||same(x,y+2*N))
            ans++;
        else
        {
            unite(x,y+N);
            unite(x+N,y+2*N);
            unite(x+2*N,y);
        }
    }
    printf("%d\n",ans);
}
