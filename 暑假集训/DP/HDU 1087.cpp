//������ε�����
//״̬ת�Ʒ����Ƕ��ˣ�����ѭ���������˵�����TT
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#define MAXN 10500
#define MAXP 10000
const int INF = -0xfffffff;   //�ص�����..һ��ʼ����̫С
using namespace std;
int a[MAXN];
int N;
int dp[MAXP];
void solve(){
	int res = a[0];
	for(int i = 0;i<N-1;i++){
	    for(int j=i+1;j<N;j++)
            if(a[j] > a[i]){
                dp[j] = max(dp[j],dp[i]+a[j]);
                res = max(res,dp[j]);
            }
	}
	printf("%d\n",res);
}
int main()
{
	while(~scanf("%d",&N)&&N){
	    memset(dp,0,sizeof(dp));
		for(int i=0;i<N;i++){
			scanf("%d",&a[i]);
			dp[i] = a[i];
		}
		solve();
	}
	return 0;
}
