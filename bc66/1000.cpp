//我来痛定思痛一下QAQ这道题唉，我太撒逼了
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int T;
    int a,b,c,l,r;
    long long maxm,minm;
    long long m;
    scanf("%d",&T);
    while(T--){
        maxm = -999999999;
        minm = 999999999;
        scanf("%d%d%d%d%d",&a,&b,&c,&l,&r);
        for(int i=l;i<=r;i++){
            m = a*i*i+b*i+c;
            maxm = max(m,maxm);
            minm = min(m,minm);
        }
        printf("%I64d %I64d\n",maxm,minm);
    }
    return 0;
}
