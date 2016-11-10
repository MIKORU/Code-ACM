#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility> //pair类
#define LL long long
using namespace std;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a));
#define MAX_N
int main()
{
    map<string ,int>a;
    string b;
    int n,t;
    ios::sync_with_stdio(0);
    while(scanf("%d",&n)!=EOF)
    {
        string c ;
        while(n--)
        {
            cin>>b;
            if(a[b]==0)
                cout<<"OH GOD"<<endl;
            else
                cout<<b<<a[b]<<endl;
            a[b]++;
        }
    }
return 0;
}
