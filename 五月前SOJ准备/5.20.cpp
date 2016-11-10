#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string a,b;
    while(cin>>a)
    {
        cin>>b;
        if(a.length()>= b.length())
            cout<<"go"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
