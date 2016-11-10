//#include <cstdio>
//#include <cstring>
//using namespace std;
//int prime[100000010];
//int size=0;
//int phi[100000005];
//char mark[100000005]={0};
//
//void prime_n(){
//    for(int i=2; i<100000005; i++)
//    {
//        if(!mark[i]) prime[size++]=i;
//        for(int j=0; j<size&&prime[j]*i<100000005; j++)
//        {
//            mark[prime[j]*i]=1;
//            if(i%prime[j]==0) break;
//        }
//    }
//}
//int main(){
//    int n;
//    prime_n();
//    phi[1]=1;
//    for(int i=2; i<100000005; i++)
//    {
//        if(!mark[i])
//        {
//            phi[i]=i-1;
//            continue;
//        }
//        for(int j=0; j<size&&prime[j]*prime[j]<=i; j++)
//        {
//            if(i%prime[j]==0)
//            {
//                if(i/prime[j]%prime[j]==0)
//                    phi[i]=prime[j]*phi[i/prime[j]];
//                else
//                    phi[i]=(prime[j]-1)*phi[i/prime[j]];
//                break;
//            }
//        }
//    }
//    while(~scanf("%d",&n)){
//            printf("%d\n",phi[n]);
//    }
//    return 0;
//}
#include<cstdio>
bool is_prime(long long n){
    for(long long i=2;i*i<=n;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    long long n = 0;
    while(~scanf("%lld",&n)){
//        if((n%2==0)&&((n/2)&1)){
//                n = n/2;
////                printf("yi\n");
//        }
//        if(n<=2){
//            printf("1\n");
////            printf("er\n");
//            continue;
//        }
        if(is_prime(n)&&n>2){
            printf("%lld\n",n-1);
//            printf("san\n");
            continue;
        }
        long long p=2,ans=n;
        while(n!=1)
        {
            if(n%p==0)
            {
                ans=ans*(p-1)/p;
                while(n%p==0) n/=p;
            }
            p++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
