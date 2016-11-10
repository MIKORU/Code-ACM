#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int p,c,a[10];
    scanf("%d",&p);
    while(p--)
    {
        scanf("%d",&c);
        for(int i=0;i<10;i++)
            scanf("%d",&a[i]);
        sort(a,a+10);
        printf("%d %d\n",c,a[7]);
    }
    return 0;
}
