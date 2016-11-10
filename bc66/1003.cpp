#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
long long comb(int m,int n){
    if(n==0) return 1;
    if(2*n>m) return comb(m,m-n);
    return comb(m,n-1)*(m-n+1)/n;
}
long long f(int x){
    long long ans = 0;
    for(int i=0;i<=x;i++){
        long long a = (long long)1<<(2*(x-i));
        a *= comb(2*x-i+1,i);
        if(i&1) a*=-1;
        ans+=a;
    }
    return ans;
}
int main()
{
    freopen("00.txt","w",stdout);
    for(int i=0;i<100;i++){
        printf("%lld\n",f(i));
    }
    return 0;
}
