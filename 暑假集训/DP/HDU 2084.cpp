//�ܵ���˵��dp�����ż���Ŀ�ɣ���ΪҪ��ʾ���״̬���̱Ƚϼ򵥣��������ϣ�dp[i][j]+=max(dp[i+1][j+1],dp[i+1][j])
//���������أ�dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j];���Ǵ��������㻹Ҫ�ж����߽��ֵ������������߽��ʱ��
//��dp[i][0]+=dp[i-1][0];�ұ߽�����dp[i][i]+=dp[i-1][j-1];
//POJ 3176�����ʽ���в�ͬ
#include<iostream>
#include<cstdio>
int dp[1001][1001]; //ȫ�������ʼ��Ϊ0
#define max(a,b) a>b?a:b
using namespace std;
int main(int i,int j)
{
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0; i<n; i++)
            for(j=0; j<=i; j++)
                cin>>dp[i][j];
        for(i=n-1; i>=0; i--)
            for(j=0; j<=i; j++)
                dp[i][j] += max(dp[i+1][j+1],dp[i+1][j]);  //��������
        cout<<dp[0][0]<<endl;
    }
    return 0;
}
