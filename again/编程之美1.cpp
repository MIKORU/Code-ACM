#include<stdio.h>
#include<cstring>
long long Count(long long n){
    //1的个数
    long long count = 0;
    //当前位
    long long Factor = 1;
    //低位数字
    long long LowerNum = 0;
    //当前位数字
    long long CurrNum = 0;
    //高位数字
    long long HigherNum = 0;
    if(n <= 0){
        return 0;
    }
    while(n / Factor != 0){
        //低位数字
        LowerNum = n - (n / Factor) * Factor;
        //当前位数字
        CurrNum = (n / Factor) % 10;
        //高位数字
        HigherNum = n / (Factor * 10);
        //如果为0,出现1的次数由高位决定
        if(CurrNum == 0){
            //等于高位数字 * 当前位数
            count += HigherNum * Factor;
        }
        //如果为1,出现1的次数由高位和低位决定
        else if(CurrNum == 1){
            //高位数字 * 当前位数 + 低位数字 + 1
            count += HigherNum * Factor + LowerNum + 1;
        }
        //如果大于1,出现1的次数由高位决定
        else{
            //（高位数字+1）* 当前位数
            count += (HigherNum + 1) * Factor;
        }
        //前移一位
        Factor *= 10;
    }
    return count;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long a;
    while(scanf("%lld",&a) != EOF){
        printf("%lld\n",Count(a));
    }
    return 0;
}
