#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
string a[10005];
bool cmp(string a,string b)
{
    string ab=a+b,ba=b+a;
    return ab<ba;
}
int main()
{
    int n,i;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n,cmp);
        for(i=0;i<n;i++)
            cout<<a[i];
        cout<<endl;
    }
    return 0;
}

