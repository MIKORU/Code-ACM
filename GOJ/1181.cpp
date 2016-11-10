#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
int H ,W;
int a[100][100];
int main()
{
    while(cin>>W)
    {
        H = 0;
        memset(a,0,sizeof(a));
        for(int i=0;i<W;i++)
        {
            int h;
            cin>>h;
            H = max (H,h);
            for(int j=0;j<h;j++)
                a[i][j] = 1;
        }
    }
    return 0;
}
