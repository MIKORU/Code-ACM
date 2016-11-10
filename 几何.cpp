#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <utility>
using namespace std;
const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x)
{
    if(fabs(x)<eps)
        return 0;
    if(x<0)
        return -1;
    else return 1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point &b)const{
        return Point(x-b.x,y-b.y);
    }
    double operator ^(const Point &b)const{
        return x*b.y-y*b.x;
    }
    double operator *(const Point &b)const{
        return x*b.x+y*b.y;
    }
    void transXY(double B)
    {
        double tx = x;
        double ty = y;
        x = tx*cos(B)-ty*sin(B);
        y = tx*sin(B)+ty*cos(B);
    }
};
struct Line{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
    }
    pair<int,Point> operator &(const Line &b)const
    {
        Point res = s;
        if(sgn((s-e)^(b.s-b.e))==0)
        {
            if(sgn((s-e)^(b.s-b.e))==0)
                return make_pair(0,res);
            else return make_pair(1,res);
        }
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return make_pair(2,res);
    }
};
double dist(Point a,Point b)
{
    return sqrt((a-b)*(a-b));
}
