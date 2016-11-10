#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include <algorithm>
using namespace std;
int a[100000];
int main()
{
    int n,m;
    double x,y;
    int k;
    int r,l,t;
    freopen("input0.txt","w",stdout);
    srand((unsigned) time(NULL)); //用时间做种，每次产生随机数不一样
    printf("100\n");
    for(int j=0;j<100;j++)
    {
        for(int i=0;i<3;i++){
            n = rand()%2000-1000;
            m = rand()%2000-1000;
            x = n;
            y = m;
            printf("%f %f\n",x,y);
        }
    }
    return 0;
}
