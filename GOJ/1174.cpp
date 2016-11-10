#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    string s;
    map<string,int>st;
    int n,i;
    while(cin>>n)
    {
        st.clear();
        for(i=0;i<n;i++)
        {
            cin>>s;
            st[s]++;
        }
        for(map<string,int>::iterator iter=st.begin();iter!=st.end();iter++)
            cout<<iter->first<<" "<<iter->second<<endl;
    }
    return 0;
}
