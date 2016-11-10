/*
    poj 1064 Cable master

    ����˼·:
        1�����ַ�ö�����п��ܵĳ��ȣ������󳤶�ֵ -- ��ν���ܳ��ȣ����ó����ܹ��������ڻ����K��
        �������������������ҳ����������������Ǹ���
        ���������ö���������������С����ķ���������ö�١���

    �ӵ㣺
        1�����ȣ����û��֮һ��
        ������ BT�������ݡ�
        4 2540
        8.02
        7.43
        4.57
        5.39

        =>0.01

        4 2542
        8.02
        7.43
        4.57
        5.39

        =>0.00

        ����������⣬���Խ��������ݳ���100������������м��㡣

        2����һ����ѡ��ȫ��������

        2 2
        1.02
        2.33

        => 1.16

        3���������ݲ���POJ discuss��ĳ��ţ�ṩ�Ĳ������ݣ�ʮ��ǿ����������trick��
*/

#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=10010;
double L[maxn];
double eps=1e-5;
int main()
{
//    freopen("00.txt","r",stdin);
//    freopen("01.txt","w",stdout);
        int n, k;
        while(~scanf("%d %d", &n, &k))
        {
            double maxvalue=0;
            for(int i=0;i<n;i++)
            {
                scanf("%lf", L+i);
                if(L[i]>maxvalue)
                    maxvalue=L[i];
            }
            double lp=0, rp=maxvalue;
            while(rp-lp>eps)
            {
                double mid=(rp+lp)/2;
                int sum=0;
                for(int i=0;i<n;i++)
                    sum+=L[i]/mid;
                if(sum>=k)
                    lp=mid;
                else
                    rp=mid;
            }
            printf("%.2f\n", int(rp*100)*0.01);   //���ȴ���
        }
    return 0;
}
