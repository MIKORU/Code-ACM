#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int P,i;
    string str;
    cin>>P;
    while(P--)
    {
        int flag = 0;
        cin >> i >> str;
        while (next_permutation(str.begin(), str.end()))
        {
            cout << i <<" " << str << endl;
            flag = 1;
            break;
        }
        if(!flag) cout<< i<<" BIGGEST"<<endl;
    }
    return 0;
}
