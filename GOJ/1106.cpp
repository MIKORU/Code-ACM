#include<stdio.h>
#include<string.h>
int main()
{
    char a[105];
    int i,m,sum;
    while(scanf("%s",&a)!=EOF)
    {
        sum=1;
        m=strlen(a);
        for(i=1;i<m;i++)
        {
            if(a[i]!=a[i-1])
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
