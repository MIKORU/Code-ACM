//被坑了一晚，虽说是水题！！
//49204K	657MS
#include <cstdio>
#include <string >
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool vis[10000000];
int time[10000000];
int last[100000];
int conver(char a)
{
    if(a=='A'||a=='B'||a=='C')
        return 2;
    if(a=='D'||a=='E'||a=='F')
        return 3;
    if(a=='G'||a=='H'||a=='I')
        return 4;
    if(a=='J'||a=='K'||a=='L')
        return 5;
    if(a=='M'||a=='N'||a=='O')
        return 6;
    if(a=='P'||a=='R'||a=='S')
        return 7;
    if(a=='T'||a=='U'||a=='V')
        return 8;
    if(a=='W'||a=='X'||a=='Y')
        return 9;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int k=0;
        bool flag = false;
        memset(vis,0,sizeof(vis));
        memset(time,0,sizeof(time));
        for(int i=0;i<n;i++)
        {
            int x=0;
            char a[100]; //数组不能开太小，否则就是坑【笑】
            scanf("%s",&a);
//            printf("%s",a);
            for(int j=0;j<strlen(a);j++)   //这里用j!='\0',就迷之错误
            {
                if(a[j]=='Q'||a[j]=='Z'||a[j]=='-')
                    continue;
                else
                {
                    if('A'<=a[j]&&a[j]<='Y')
                        x = x*10+conver(a[j]);
                    else
                        x = x*10+(a[j]-'0');
                }
            }
//printf("%d",x);
            time[x]++;
            if(!vis[x]&&time[x]>=2)
            {
                flag = true;
                last[k++]=x;
                vis[x]= true;
            }
        }

        if(!flag)
            printf("No duplicates.\n");
        else
        {
            sort(last,last+k);
            for(int i=0;i<k;i++)
                printf("%03d-%04d %d\n",last[i]/10000,last[i]%10000,time[last[i]]);  //傻逼错误WA一发
        }
    }
    return 0;
}
