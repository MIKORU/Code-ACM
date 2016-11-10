#include "iostream"

using namespace std;

int main()
{
    int m,d,monthmax,y;
    while(cin>>y>>m)
    {

        //判断年份和月份
        if(y%4==0||(y%100==0&&y%400==0))//闰年
        {
            if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
                monthmax=31;
            if(m==2)
                monthmax=29;
            if(m==4||m==6||m==9||m==11)
                monthmax=30;
        }
        if(y%4!=0)//平年
        {
            if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
                monthmax=31;
            if(m==2)
                monthmax=28;
            if(m==4||m==6||m==9||m==11)
                monthmax=30;
        }

        //基姆拉尔森计算公式取得一号周几
        if(m==1||m==2)
        {
            m+=12;    //一月算做上一年的十三月，二月算做上一年的十四月
            y--;
        }
        d=(2+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;//算出这月一号周几
        if(d==0)
        {
            d=7;
        }
        //输出日历
        {
            {
                //标题模块
                if(m==13)
                {
                    cout<<"   公元"<<y+1<<"年 第1月日历"<<endl;
                }
                if(m==14)
                {
                    cout<<"   公元"<<y+1<<"年 第2月日历"<<endl;
                }
                if(m!=13&&m!=14)
                {
                    cout<<"   公元"<<y<<"年 第"<<m<<"月日历"<<endl;
                }
            }
            cout<<" 1   2   3   4   5   6   7   "<<endl;
            for(int i=1; i<=d-1; i++)
            {
                cout<<"    ";
            }
            for(int j=1; j<=monthmax; j++)
            {
                if(j<10)
                {
                    cout<<" "<<j<<"  ";
                }
                if(j>=10)
                {
                    cout<<" "<<j<<" ";
                }
                if((j+d-1)%7==0)
                {
                    cout<<endl;
                }
                if(j==monthmax)
                {
                    cout<<endl;
                }
            }
            cout<<endl;
        }
    }
}
