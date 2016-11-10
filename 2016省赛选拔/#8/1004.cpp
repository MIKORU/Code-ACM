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
#define MAX_N
const int INF = 0x3f3f3f3f;
using namespace std;
struct point
{
    double x;
    double y;
}circle,a,b,c,d;
double r;
double dis(point &a,point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    int T;
    scanf("%d",&T);
    point P;
    while(T--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf",&circle.x,&circle.y,&r,&a.x,&a.y,&b.x,&b.y);
        if(a.x > b.x){
            P=a;
            a=b;
            b=P;
        }
        c.x=a.x;
        c.y=b.y;
        d.x=b.x;
        d.y=a.y;
        if(dis(a,circle)<r && dis(b,circle) <r && dis(c,circle)<r && dis(d,circle) <r){
            printf("no\n");
            continue;
        }
        if(circle.x>=a.x && circle.x<=b.x)
        {
            if(fabs(circle.y-a.y) <= r || fabs(circle.y-b.y) <= r){
                printf("yes\n");
                continue;
            }
        }
        if((circle.y >= a.y && circle.y <=b.y) || (circle.y>=b.y && circle.y<=a.y))
        {
            if(fabs(circle.x-a.x) <=r || fabs(circle.x-b.x) <=r){
                printf("yes\n");
                continue;
            }
        }
        if(dis(a,circle)<=r || dis(b,circle) <=r || dis(c,circle)<=r || dis(d,circle) <=r){
                printf("yes\n");
                continue;
        }
        printf("no\n");
    }
    return 0;
}
