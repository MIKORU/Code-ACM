#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    int i;
    string a;
    while(cin>>a)
    {
        stack<char>st;
        for(i=0;i<a.length();i++)
        {
            if(st.empty()||a[i]=='('||a[i]=='[')
                st.push(a[i]);
            if(a[i]==']'&&st.top()!='['||a[i]==')'&&st.top()!='(')
                st.push(a[i]);
            if(a[i]==']'&&st.top()=='['||a[i]==')'&&st.top()=='(')
                st.pop();
        }
        if(!st.empty())
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}
