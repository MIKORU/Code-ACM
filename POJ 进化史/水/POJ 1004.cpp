//216K	0MS
//这题非常傻逼，然而....我看不懂题意，其实能大概猜出来的样子擦....英文是硬伤
#include <iostream>
using namespace std;
int main()
{
    double nowmoney;
    while(cin>>nowmoney)
    {
        double temp = 0;
        double ans = nowmoney;
        for(int i=1;i<12;i++)
        {
            cin>>temp;
            ans+=temp;
        }
        ans = ans/12;
        cout<<"$"<<ans<<endl;
    }
    return 0;
}
