#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int n;
int main()
{
    int T;
    map<string ,int >p;
    cin>>T;
	while(T--)
    {
        cin >> n;
        int ans = 1;
        for (int i=0; i<n; i++)
        {
            string str[2];
            cin >> str[0] >> str[1];
            p[str[1]]++;
        }
        for(map<string,int>::iterator iter=p.begin();iter!=p.end();iter++)
        {
            if(iter->second == n)
            {
                ans = 0;
                break;
            }
            ans*=iter->second;
        }
        cout<<ans+n<<endl;
    }
	return 0;
}
