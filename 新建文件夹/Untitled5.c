#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define INF 0x3f3f3f3f

int big,m,n;
int step[4][2]={0,1,1,0,-1,0,0,-1};
int a[10][10];
int ok[10][10];
int ans=0;

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}


void dfs(int a0,int b)
{
    if(a0==m-1&&b==n-1)
    {
        big=max(big,ans);
        //printf("mmm %d \n",big);
        return;
    }
        int i,x,y;


    for(i=0;i<4;i++)
    {
        if(a0==m-1&&i==3)
            continue;
        if(b==n-1&&i==2)
            continue;
        if(a0==0&&i==3)
            continue;
            if(b==0&&i==2)
                continue;
        x=step[i][0]+a0;
        y=step[i][1]+b;

        if(x>=0&&x<m &&y>=0&&y<n&& ok[x][y]==0)
        {
            ans+=a[x][y];
            ok[x][y]=1;
            //printf("%d %d %d\n",x,y,big);
            dfs(x,y);
            ans=ans-a[x][y];
            ok[x][y]=0;
        }
    }
}

int main()
{
    int i,j,k;
    int ca=1;
    while(scanf("%d%d",&m,&n)==2)
    {
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    memset(ok,0,sizeof(ok));
    ans=a[0][0];
    ok[0][0]=1;
    big=-INF;
    dfs(0,0);
    printf("Case %d: %d\n",ca++,big);
    }
    return 0;
}
