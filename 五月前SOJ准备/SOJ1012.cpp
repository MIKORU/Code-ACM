#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int MAX_N = 100;
double a[MAX_N];
int main()
{
    int n;
    double t;
    while(cin>>n)
    {
        if(n==0) break;
        double y = 1;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<n-1;i++)
        {
            t = (a[i]-a[i+1])/2;
            y += sqrt(4-(t*t));
        }
        printf("%.4f %.4f\n",(a[n-1]+a[0])/2,y);
    }
    return 0;
}
