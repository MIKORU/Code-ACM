#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // È¡¾ø¶ÔÖµ //
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility> //pair<int int >a[?]
using namespace std;
int DAY = 1;
int MON = 1;
int YEAR = 2001;
int days(int y,int m)
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
int sumday(int y,int m)
{
    int s=0,i,j;
    for(i=YEAR;i<=y;i++)
        for(j=1;j<=12;j++)
            s+=days(i,j);
    for(i=MON;i<m;i++)
        s+=days(y,i);
    return s;
}
int main()
{
    int yu,mu,du;
    int ny,nm,nd;

    int i,j;
    while(scanf("%d%d%d%d%d%d",&yu,&mu,&du,&ny,&nm,&nd)!=EOF)
    {
        int day1=0,day2=0;
        day1+=sumday(yu,mu)+(du==29?28:du);
        day2+=sumday(ny,nm)+(nd==29?28:nd);
        printf("%d\n",day2-day1);
    }
return 0;
}
