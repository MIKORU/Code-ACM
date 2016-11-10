#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define N 1005
string a;
struct node
{
    string e;
    int v;
}b[N];
bool f(string x,string y)
{
    if(x+y==a)
        return 1;
    return 0;
}
int main()
{

    int i,j,n;
    while(cin>>a)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>b[i].e;
            cin>>b[i].v;
            if(i>0&&f(b[i].e,b[i-1].e))



    }

return 0;
}
