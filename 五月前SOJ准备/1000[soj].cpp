#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
    int n,ok,z;
    string a,b,c;
    while(cin>>n)
    {
        cin>>a;
        while(n--)
        {
            cin>>b;
            int ok = 1;
            if(a.length()-1>b.length())
                ok=0;
            for(int j=0;a[j]!=42;j++)
                if(b[j]!=a[j])
                {
                    ok = 0;
                    break;
                }
            for(int j=b.length()-1,z=a.length()-1;a[z]!=42;j--,z--)
                if(b[j]!=a[z])
                {
                    ok = 0;
                    break;
                }
            if(ok==1) cout<<"DA"<<endl;
            else cout<<"NE"<<endl;
        }
    }
    return 0;
}
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//
//using namespace std;
//
//int n, d, a, b;
//int bb[1<<17], bp[1<<17], pb[1<<17], pp[1<<17], SIZE=(1<<16);
//
//void update(int node) {
//    int l=node*2, r=node*2+1;
//    pp[node] = max(pb[l]+pp[r], pp[l]+bp[r]);
//    pb[node] = max(pb[l]+pb[r], pp[l]+bb[r]);
//    bp[node] = max(bb[l]+pp[r], bp[l]+bp[r]);
//    bb[node] = max(bb[l]+pb[r], bp[l]+bb[r]);
//}
//
//int main() {
//
//    while(~scanf("%d%d", &n, &d))
//    {
//        for(int i=0;i<n;i++)
//            scanf("%d\n", &bb[SIZE+i]);
//        for(int i=SIZE-1;i>0;i--)
//            update(i);
//        long long ans=0;
//        for(int i=0;i<d;i++)
//        {
//            scanf("%d %d", &a, &b);
//            a--;
//            bb[SIZE+a] = b;
//            for(int j=(SIZE+a)/2;j>0;j/=2)
//                update(j);
//            ans += bb[1];
//        }
//        printf("%lld\n", ans);
//    }
//return 0;
//}
