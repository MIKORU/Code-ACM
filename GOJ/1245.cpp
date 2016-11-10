#include<stdio.h>
int main()
{
    int T,e,ans;

    while(~scanf("%d",&T))
    {
        int pre = 0;
        int fis = 1;
        ans = 0;
        while(T--)
        {
            scanf("%d",&e);
            if(fis&&e)
            {
                ans++;
                fis = 0;
            }
            else
            {
                if(!pre&&e)
                    ans+=2;
                if(pre&&e)
                    ans++;
            }
            pre = e;
        }
        printf("%d\n",ans);
    }
    return 0;
}
