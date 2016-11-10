#include <algorithm>
#include <iostream>
#include <set>
#define N 100005
using namespace std;
int main()
{
    int n,a[N],b[N],ans;
    ios::sync_with_stdio(0);
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b,b+n);
        int flag = 1;
        for(int i=0;i<n;i++)
        {
            ans=upper_bound(b,b+n,a[i])-b;
            if(flag)
            {
                cout<<n-ans;
                flag = 0;
            }
            else cout<<" "<<n-ans;
        }
        cout<<endl;

    }
    return 0;
}

