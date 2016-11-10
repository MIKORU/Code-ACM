#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>  //priority_queue<int>
#include <vector>
#include <map>
#include <set>
#include <utility> //pair类或者 typedef pair<int ,int>P;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a))  //大数 memset(a,0x7f,sizeof(a));
#define eps 1e-10
using namespace std;
double area2(double x0,double y0,double x1,double y1,double x2,double y2)
{
	return fabs(x0*y1+x2*y0+x1*y2-x2*y1-x0*y2-x1*y0);
}
int main()
{
	int i,j,ans;
	double x0,x1,x2,y0,y1,y2,s0,s1,s2,s3;
	double minX,maxX,minY,maxY;
	while(~scanf("%lf%lf%lf%lf%lf%lf",&x0,&y0,&x1,&y1,&x2,&y2))
	{
	    if(x0==0&&y0==0&&x1==0&&y1==0&&x2==0&&y2==0) break;
		minX=min(x0,min(x1,x2));
		minY=min(y0,min(y1,y2));
		maxX=max(x0,max(x1,x2));
		maxY=max(y0,max(y1,y2));
		ans=0;
        for(i=minX;i<=maxX;i++)
			for(j=minY;j<=maxY;j++)
			{
                if((i-x0)*(y1-y0)==(j-y0)*(x1-x0)) continue;
                if((i-x0)*(y2-y0)==(j-y0)*(x2-x0)) continue;
                if((i-x2)*(y1-y2)==(j-y2)*(x1-x2)) continue;
				s0=area2(x0,y0,x1,y1,x2,y2);
				s1=area2(i,j,x0,y0,x1,y1);
				s2=area2(i,j,x1,y1,x2,y2);
				s3=area2(i,j,x2,y2,x0,y0);
				if(fabs(s0-s1-s2-s3)<eps)
					ans++;
			}
		printf("%d\n",ans);
	}
	return 0;
}
