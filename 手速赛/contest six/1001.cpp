#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    int m,k;
    while(scanf("%d",&n)!=EOF)
    {
        if(n>0)
            printf("%d\n",n%12);
        else printf("%d\n",12-(-n%12));
    }
    return 0;
}

