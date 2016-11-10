#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 1000000+10;
char str[maxn];
int k;
map<char,int>p;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s%d",str,&k);
        //printf("%s\n%d\n",str,k);
        int length = strlen(str);
        printf("length = %d\n",length);
        int s=0,t=0,num =0;
        int res = 0;
        for(;;){
            while(t<length&&num<k){

                if(p[str[t++]]++ == 0){
                    num++;
                    //printf("t=%d  %c  %d num=%d\n",t,str[t],p[str[t]],num);
                }
                else{
                    --p[str[s]];
                    s ++;

                    num = 0;
                }

            }
            if(num<k) break;
            res ++;
            --p[str[s++]];
            num--;
            printf("s=%d  %c  %d\n",s,str[s],p[str[s]]);
        }
        printf("%d\n",res);
    }
    return 0;
}
