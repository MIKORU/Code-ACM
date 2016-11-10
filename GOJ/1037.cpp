#include <stdio.h>
int main()
{
    int n2, n5, i, j, n, digit;
    while(scanf("%d",&n)!=EOF)
    {
        digit = 1;
        n2 = n5 = 0;
        for(i=2; i<=n; i++)
        {
            j = i;
            while(j%2 == 0)
            {
                n2++;
                j /= 2;
            }
            while(j%5 == 0)
            {
                n5++;
                j /= 5;
            }
            digit = (digit * j) % 10;
        }
        for(i=0; i<n2-n5; i++)
            digit = (digit * 2) % 10;
        printf("%5d -> %d\n",n,digit);
    }
    return 0;
}
/*从2到n，每次更新digit,都先求出该数的2和5的个数，每对2和5相互抵消，每次计算都对10取模，减小计算量。显然2的个数一定比5的个数多。*/
