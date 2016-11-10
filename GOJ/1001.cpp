#include<stdio.h>
int main()
{
    int N=0,M=0,i=0,a[41];
    scanf("%d",&N);
    a[1]=1;
    a[2]=1;
    for(i=3;i<=40;i++)
        a[i]=a[i-1]+a[i-2];
    while(N--)
    {
        scanf("%d",&M);
        printf("%d\n",a[M]);
    }
return 0;
}
