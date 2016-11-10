#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000000;
char str[maxn];
int vis[maxn];
int sum[maxn];
struct STACK{
    char c;
    int loc;
};
STACK s[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        int len = strlen(str);
        int p = -1;
        for(int i=0;i<len;i++)
        {
            if(p!=-1)
            {
                if(str[i]==')'&&s[p].c=='(')
                {
                    p--;
                    continue;
                }
                if(str[i]==']'&&s[p].c=='[')
                {
                    p--;
                    vis[i]++;
                    continue;
                }
                s[++p].c = str[i];
                s[p].loc = i;
            }
            else
            {
                s[++p].c = str[i];
                s[p].loc = i;
            }
        }
        sum[0] = vis[0];
        for(int i=1;i<len;i++)
        {
            sum[i]= sum[i-1]+vis[i];
        }
        if(p==-1)
        {
            printf("%d\n%s\n",sum[len-1],str);
            continue;
        }
        int x=-1,y=-1,ans=0;
        int ansx = -1,ansy=-1;
        for(int i=0;i<=p;i++)
        {
            y = s[i].loc;
            int tmpans = sum[y-1]-sum[x]+(x==0?vis[x]:0);
            if(tmpans > ans)
            {
                ans = tmpans;
                ansx = x+1;
                ansy = y-1;
            }
            x = y;
        }
        y = len;
        int tmpans = sum[y-1]-sum[x]+(x==0?vis[x]:0);
        if(tmpans > ans)
        {
            ans = tmpans;
            ansx = x+1;
            ansy = y-1;
        }
        printf("%d\n",ans);
        if(ans>0)
        {
            for(int i=ansx;i<=ansy;i++)
                printf("%c",str[i]);
            putchar('\n');
        }
    }
    return 0;
}
