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
/*��2��n��ÿ�θ���digit,�������������2��5�ĸ�����ÿ��2��5�໥������ÿ�μ��㶼��10ȡģ����С����������Ȼ2�ĸ���һ����5�ĸ����ࡣ*/
