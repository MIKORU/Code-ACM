#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    int i,j,c,n,t;
    map<string,int>st;
    string s;
    while(cin>>n)
    {
        st.clear();
        for(i=0;i<n;i++)
        {
            cin>>s>>t;
            st[s]=t;
        }
        cin>>s;
        c=0;
        for(i=0;i<=s.length();i++)
            for(j=0;i+j<=s.length();j++)
                c+=st[s.substr(j,i)];
        cout<<c<<endl;
    }
    return 0;
}
