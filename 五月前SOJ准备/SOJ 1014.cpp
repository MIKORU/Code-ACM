#include <stdio.h>
int main()
{
    int a,b,c;
    for(int i=2992;i<=9999;i++)
    {
        a = (i/1000)+(i%1000/100)+(i%100/10)+(i%10);
        b = (i/1728)+(i%1728/144)+(i%144/12)+(i%12);
        c = (i/4096)+(i%4096/256)+(i%256/16)+(i%16);
        if(a==b&&b==c)
            printf("%d\n",i);
    }
    return 0;
}
