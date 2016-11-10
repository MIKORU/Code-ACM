#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct Date  ///定义日期结构体
{
    int yy,mm,dd;
    bool isLeapY()
    {
        return (yy%400==0)||(yy%4==0)&&(yy%100!=0);
    }
    int daysinMon()
    {
        if(this->isLeapY()&&mm==2)
            return 29;
        else
            return month[mm];
    }
    void setDate(int y,int m,int d)
    {
        yy=y;
        mm=m;
        dd=d;
    }
    int Weekday()
    {
        int d=dd,m=mm>2?mm-2:mm+10,Year=mm>2?yy:yy-1,c=Year/100,y=Year%100;
        return (d+(13*m-1)/5+c/4+y+y/4+5*c)%7;
    }
};


int main()
{
    Date a;
    int n,week[7];
    while(cin>>n)
    {
        memset(week,0,sizeof(week));

        for(int i=1900;i<1900+n;i++)
        {
            for(int j=1;j<=12;j++)
            {
                a.setDate(i,j,13);

                week[a.Weekday()]++;
            }
        }
        cout<<week[6]<<" "<<week[0]<<" "<<week[1]<<" "<<week[2]<<" "<<week[3]<<" "<<week[4]<<" "<<week[5]<<endl;
    }

}
