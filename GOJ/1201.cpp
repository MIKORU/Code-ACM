#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<iostream>
using namespace std;
#define N 100005

int main()
{
    double x1,x2,x3,y1,y2,y3,a,b,c;
    while(~scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3))
    {
        double m1=x2-x1,m2=x3-x2,n1=y2-y1,n2=y3-y2,m3=x3-x1,n3=y3-y1,l1=x2*x2-x1*x1,l2=x3*x3-x2*x2,l3=x3*x3-x1*x1;
        if(x1==x2||x2==x3||x1==x3) {printf("SB\n");continue;}
        if(y1==y2&&y2==y3) {printf("SB\n");continue;}
        if(n1/m1==n2/m2) {printf("SB\n");continue;}
        a=(m1*n2-m2*n1)/(m1*l2-m2*l1);
        b=(n1-a*l1)/m1;
        c=y1-a*x1*x1-b*x1;
        printf("a=%f,b=%f,c=%f.\n",a,b,c);
    }
	return 0;
}
