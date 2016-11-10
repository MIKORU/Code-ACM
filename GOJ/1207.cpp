#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<iostream>
using namespace std;
#define N 100005

//map<int,int>num;
//int main()
//{
//    int n,m,t;
//    while(~scanf("%d%d",&n,&m))
//    {
//        num.clear();
//        for(int i=1;i<=n+m;i++)
//        {
//            scanf("%d",&t);
//            num[t]++;
//        }
//        map<int,int>::iterator it=num.begin();
//        int flag=1;
//        for(;it!=num.end();it++)
//        {
//            if(it->second==2)
//            {
//                if(flag) {printf("%d",it->first);flag=0;}
//                else printf(" %d",it->first);
//            }
//        }
//        printf("\n");
//    }
//	return 0;
//}
int main()
{
    int n,m,t;
    while(~scanf("%d%d",&n,&m))
    {
        set<int>A;
        set<int>B;
        set<int>C;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t);
            A.insert(t);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&t);
            B.insert(t);
        }
        set_intersection(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.begin()));
        int flag = 1;
        for(set<int>::iterator it=C.begin();it!=C.end();it++)
        {
            if(flag)
            {
                printf("%d",*it);
                flag = 0;
            }
            else printf(" %d",*it);
        }
        putchar('\n');
    }
    return 0;
}
