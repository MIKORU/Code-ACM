#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // ȡ����ֵ
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>  //priority_queue<int>
#include <vector>
#include <map>
#include <set>
#include <utility> //pair����� typedef pair<int ,int>P;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a))  //���� memset(a,0x7f,sizeof(a));
#define MAX_N
const int INF = 0x3f3f3f3f;
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1 ///��ʾrt*2+1;
using namespace std;
const int maxn = 55555;
int sum[maxn<<2];
void PushUP(int rt){  ///��ǰ�ڵ���µ����ڵ�
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];  ///���ڵ������ڵ�֮��
}
void build(int l,int r,int rt){  ///��������
    if(l == r){
        ///���еײ�Ĳ��� ��ȡorֱ�Ӹ�ֵ
        return ;
    }
    int m = (l + r)>>1;
    build(lson);
    build(rson);
    PushUP(rt);
}
///������� ����
void update(int p,int add,int l,int r,int rt){
    if(l == r){
        ///����ĿҪ��
        return ;
    }
    int m = (l + r)>>1;
    if(p <= m)
        update(p,add,lson);  ///p��ʾҪ������ȥ�ĵ� add��ʾ����Ĳ���
    else update(p,add,rson);
    PushUP(rt);  ///���ݸ��¸��ڵ�
}
///������� ��ֵ
int query(int L,int R,int l,int r,int rt){  ///��ѯL��R֮��
    if(L <= l && r <= R){  ///���ڷ�Χ�� ���ظ��ڵ�
        return sum[rt];
    }
    int m = (l + r)>>1;
    int ret = 0;
    if(L <= m)
        ///�������� ��� ������������Сֵ�ȵ�
    if(R > m)
        ///�������� ��� ������������Сֵ�ȵ�
    return ret;
}
int main()
{

    while(scanf("")!=EOF)
    {

    }
return 0;
}
