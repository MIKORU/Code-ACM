#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // ȡ����ֵ
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>  //priority_queue<int>
#include <vector>
#include <map>
#include <set>
#include <utility> //pair����� typedef pair<int ,int>P;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a))  //���� memset(a,0x7f,sizeof(a));
#define MAX_N 100005
const int INF = 0x3f3f3f3f;
using namespace std;
string a;
string b;
int main()
{

    while(cin>>a>>b){
        int cnt=0;
        int length=a.size();
        if(a==b){
            cout<<a<<endl;
            continue;
        }
        for(int i=0; i<length; i++){
            if(a[i]!=b[i])
                cnt++;
        }
        if(cnt%2==1) printf("impossible\n");
        else{
            cnt/=2;
            for(int i=0; i<length; i++){
                if(a[i]!=b[i]){
                    if(cnt>0){
                        cout<<a[i];
                        cnt--;
                    }
                    else
                        cout<<b[i];
                }
                else
                    cout<<a[i];
            }
        }
        printf("\n");
    }
return 0;
}
