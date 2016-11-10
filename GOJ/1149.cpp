#include <stdio.h>
#define N 11000
#define X 51000
int a[N],c[N];
char b[X];
int main()
{
    //freopen("01.txt","w",stdout);
    int i,j=0,k,n;
    for(i=0,k=11000;k>0;i++,k--)
        a[i]=k;
    for(i=0;i<11000;i++)
    {
        while(a[i]!=0)
        {
            b[j++]=a[i]%10+'0';
            a[i]/=10;
        }
    }
    b[j++]='\0';
    for(j=j-2,i=0;j>=3;j-=4)
    {
        c[i++]=(b[j]-'0')*1000+(b[j-1]-'0')*100+(b[j-2]-'0')*10+(b[j-3]-'0');
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",c[n-1]);
    }
    return 0;
}
