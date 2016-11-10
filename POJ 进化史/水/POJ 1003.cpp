//216K	0MS
#include <iostream>
using namespace std;
int main()
{
    double n;
    while(cin>>n)
    {
        double i = 2;
        int ans = 0;
        double temp = 0;
        if(n==0.0) break;
        while(temp < n)
        {
            temp +=1/i;
            i++;
            ans++;
        }
        cout<<ans<<" card(s)"<<endl;
    }
    return 0;
}
