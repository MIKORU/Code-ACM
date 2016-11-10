//(A+T)/(C+G) 0.8
//0.8 0.8
//(A+C)/(G+T) 0.8
//1.25 1
//(A+G)/(C+T) 0.5
//2 1
#include <stdio.h>
#include <string.h>
char a[100];
int main()
{
//    freopen("00.txt","r",stdin);
//    freopen("01.txt","w",stdout);
    double n;
    while(scanf("%s",a)!=EOF)
    {
        scanf("%lf",&n);
        if(a[3]=='T')
            printf("%.2f %.2f\n",n,n);
        else printf("%.2f 1.00\n",1/n);
    }
    return 0;
}
