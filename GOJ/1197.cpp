#include <cstring>
#include <iostream>
using namespace std;
int get(int y,int m)
{
    int i;
    if((y%4==0&&y%100!=0)||(y%400==0)) i=1;
    else i=0;
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    return 31;
    else if (m==2)
        {
            if(i==1)
            return 29;
            else return 28;
        }
    return 30;
}
int main()
{
    int n,a[7],week, i,j;
    while(cin>>n)
    {
        week=6;
        memset(a,0,sizeof(a));
        for( i=1900;i<=1900+n-1;i++)
            for( j=1;j<=12;j++)
            {
                a[week%7]++;
                week+=get(i,j);
            }
        cout<<a[6]<<" "<<a[0]<<" ";
        for(i=1;i<5;i++)
            cout<<a[i]<<" ";
        cout<<a[5]<<endl;
    }
    return 0;
}
