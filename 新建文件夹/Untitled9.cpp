#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
bool is_prime[100000005];
bool is_prime_small[100005];
typedef long long ll;
ll a,b;
ll ans;
void segment_sieve(ll a,ll b)
{
    for(int i=0;(ll)i*i<b;i++)
    {
        is_prime_small[i] = true;
    }
    for(int i=0;i<b-a;i++)
        is_prime[i] = true;
    for(int i=2;(ll)i*i<b;i++)
    {
        if(is_prime_small[i]){
            for(int j=2*i;(ll)j*j<b;j+=i)
                is_prime_small[j] = false;
            for(ll j = max(2LL,(a+i-1)/i)*i;j<b;j+=i)
                is_prime[j-a] = false;
        }
    }
}
int main()
{
    while(~scanf("%lld%lld",&a,&b)){
        ans = 0;
        segment_sieve(a,b+1);
        for(ll i=0;i<b-a+1;i++){
            if(is_prime[i])
                ans++;
        }
        if(a==1)
            printf("%lld\n",ans-1);
        else
            printf("%lld\n",ans);
    }
    return 0;
}
