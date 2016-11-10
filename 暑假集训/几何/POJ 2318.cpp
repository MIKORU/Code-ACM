//#include <cstdio>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//struct Point{
//    int x,y;
//    Point(){}
//    Point(int _x,int _y){
//        x = _x;
//        y = _y;
//    }
//    Point operator -(const Point &c)const{
//        return Point(x-c.x,y-c.y);
//    }
//    int operator *(const Point &c)const{
//        return x*c.x+y*c.y;
//    }
//    int operator ^(const Point &c)const{
//        return x*c.y-y*c.x;
//    }
//
//};
//struct Line{
//    Point a,b;
//    Line(){}
//    Line(Point _a,Point _b){
//        a = _a;
//        b = _b;
//    }
//};
//int X(Point a,Point b,Point c){
//    return (b-a)^(c-a);
//}
//Line line[5500];
//int n,m,x1,x2,y2;
//int area[5500];
//int main()
//{
//    while(~scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2)&&n){
//        int Ui,Li;
//        for(int i=0;i<n;i++){
//            scanf("%d%d",&Ui,&Li);
//            line[i]=Line(Point(Ui,y1),Point(Li,y2));
//        }
//        line[n] = Line(Point(x2,y1),Point(x2,y2));
//        while(m--){
//            Point toy;
//            int x,y;
//            scanf("%d%d",&x,&y);
//            toy = Point(x,y);
//            int l=0,r=n,tmp,mid;
//            while(r-l>=1){
//                mid = (l+r)/2;
//                if(X(toy,line[mid].a,line[mid].b)<0){ //叉积大于零 顺时针 右边
//                    tmp = mid;
//                    r = mid - 1;
//                }
//                else l = mid+1;
//            }
//            area[mid]++;
//        }
//    }
//    return 0;
//}

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <math.h>
//这题前面自己打的不晓得哪里的问题
using namespace std;
struct Point         //定义点的结构题目
{
    int x,y;
    Point(){}
    Point(int _x,int _y)
    {
        x = _x;y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }
    int operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
    int operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
};
struct Line             //定义线
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;e = _e;
    }
};

int xmult(Point p0,Point p1,Point p2) //计算p0p1 X p0p2 叉积
{
    return (p1-p0)^(p2-p0);
}
const int MAXN = 5050;
Line line[MAXN];
int ans[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,x1,y1,x2,y2;
    bool first = true;   //打印要求
    while(~scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2)&& n)
    {
        if(first)
            first = false;
        else printf("\n");
        int Ui,Li;
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d",&Ui,&Li);
            line[i] = Line(Point(Ui,y1),Point(Li,y2));
        }
        line[n] = Line(Point(x2,y1),Point(x2,y2));
        int x,y;
        Point p;
        memset(ans,0,sizeof(ans));
        while( m-- )                       //线略多 分了很多区域 对一个个点二分逼近，最后确定在哪个区域
        {
            scanf("%d%d",&x,&y);
            p = Point(x,y);
            int l = 0,r = n;
            int tmp;  //表示哪个区域
            while( l <= r)
            {
                int mid = (l + r)/2;
                if(xmult(p,line[mid].s,line[mid].e) < 0)
                {
                    tmp = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            ans[tmp]++;
        }
        for(int i = 0; i <= n;i++)
            printf("%d: %d\n",i,ans[i]);
    }
    return 0;
}
