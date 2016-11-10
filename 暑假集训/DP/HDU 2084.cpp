//总的来说是dp的入门级题目吧，因为要表示这个状态方程比较简单，从下往上：dp[i][j]+=max(dp[i+1][j+1],dp[i+1][j])
//从上往上呢：dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j];但是从上往下你还要判断两边界的值，当它处于左边界的时候
//有dp[i][0]+=dp[i-1][0];右边界则是dp[i][i]+=dp[i-1][j-1];
//POJ 3176输入格式略有不同
#include<iostream>
#include<cstdio>
int dp[1001][1001]; //全局数组初始化为0
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
                dp[i][j] += max(dp[i+1][j+1],dp[i+1][j]);  //自下向上
        cout<<dp[0][0]<<endl;
    }
    return 0;
}
