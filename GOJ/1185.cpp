#include<cstdlib>
#include<cstring>
#include<iostream>
#define N 1000+5
#define maxx(a,b) a>b?a:b
using namespace std;
int dp[N][N];
char str1[N],str2[N];
int LCSL(int len1,int len2)
{
    int i,j;
    int len=maxx(len1,len2);
    for(i=0;i<=len;i++)
        dp[i][0]=0;dp[0][i]=0;
    for(i=1;i<=len1;i++)
        for(j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=maxx(dp[i-1][j],dp[i][j-1]);
        }
    return dp[len1][len2];
}
int main()
{
    int flag,i,j;
    while(cin>>str1)
    {

        flag=0;
        int len1=strlen(str1);
        for (i=0,j=len1-1;i<=j;i++,j--)
		{
			if (str1[i]!=str1[j])
			{
				flag=1;
				break;
			}
		}
        for(i=len1-1,j=0;i>=0;i--,j++)
            str2[j]=str1[i];
        int len2=strlen(str2);
        if(flag==1) cout<<len1-LCSL(len1,len2)<<endl;
        else cout<<"0"<<endl;
        memset(str1,0,sizeof(str1));
        memset(str2,0,sizeof(str2));
    }
return 0;
}
