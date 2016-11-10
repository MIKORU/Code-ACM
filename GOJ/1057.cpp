/*本题思路：
1,令M=N^N；

2，分别对等式两边取对数得 log10(M)=N*log10(N),得M=10^(N*log10(N))；

3，令N*log10(N)=a+b,a为整数，b为小数；

4，C函数：log10()，计算对数，pow(a,b)计算a^b

5，由于10的任何整数次幂首位一定为1,所以,M的首位只和N*log10(N)的小数部分有关，

  即只用求10^b救可以了；

6，最后对10^b取整，输出取整的这个数就行了。（因为0<=b<1,所以1<=10^b<10对

其取整，那么的到的就是一个个位，也就是所求的数）。
*/

#include<stdio.h>
#include<math.h>
int main()
{
  int test;
  double n,k,a;
  scanf("%d",&test);
  while(test--)
  {
    scanf("%lf",&n);
    a=n*log10(n);
    k=a-(long long)a; //这里强制转换需要用int64才能A，否则会w或者CE！！！
    printf("%d\n",int(pow(10,k)));
  }
  return 0;
}


