//216K	0MS
//����ǳ�ɵ�ƣ�Ȼ��....�ҿ��������⣬��ʵ�ܴ�Ų³��������Ӳ�....Ӣ����Ӳ��
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
