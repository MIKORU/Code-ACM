//POJ 1887
//Çó×î³¤ÏÂ½µ×ÓÐòÁÐÎÊÌâ ²Î¼û°×Êé×î³¤ÉÏÉý×ÓÐòÁÐÎÊÌâ
//唯一的问题大概就是输出比较坑了666
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 1000010;
int a[MAX_N];
int dp[MAX_N];
int n;
int num ;
    int cas = 0;
void solve(){
    int res = 0;
    for(int i=0;i<num;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(a[j]>a[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        res = max(res,dp[i]);
    }
    printf("Test #%d:\n  maximum possible interceptions: %d\n\n",cas,res);
}
int main()
{
    int temp;
    while(~scanf("%d",&temp)&&temp!=-1){
        cas++;
        num = 0;
        a[num++] = temp;
        while(~scanf("%d",&temp)&&temp!=-1){
            a[num++] = temp;
        }
        solve();
    }
    return 0;
}
