#include <iostream>
#include <algorithm>
using namespace std;
//#define max(a,b) a>b?a:b
//#define min(a,b) a>b?b:a
#define N 100005
int mian()
{
    int T,n,i,a[N],s,l;
    cin>>T;
    while(T--)
    {
        s=N;
        l=-N;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            s=(s,a[i]);
            l=(l,a[i]);
        }
        cout<<l-s<<endl;
    }
    return 0;
}
