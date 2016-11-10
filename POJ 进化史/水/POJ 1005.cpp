//220K	16MS
#include <iostream>
#include <algorithm>
#include <cmath>
const double PI = 3.1415926;
using namespace std;
int main()
{
    int T;
    double x,y;
    while(cin>>T)
    {
        int num = 1;
        while(T--)
        {
            double r = 0;
            double area = 0;
            int ans = 0;
            cin>>x>>y;
            double R = sqrt(x*x+y*y);
            while(r < R)
            {
                ans++;
                area += 50;
                r = sqrt(area*2/PI);
            }
            cout<<"Property "<<num++<<": This property will begin eroding in year "<<ans<<"."<<endl;
        }
        cout<<"END OF OUTPUT."<<endl;
    }
    return 0;
}
