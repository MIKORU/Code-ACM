//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h> // ȡ����ֵ
//#include <iostream>
//#include <algorithm>
//#include <stack>
//#include <map>
//#include <set>
//#include <utility> //pair��
//#define LL long long
//using namespace std;
//#define LL long long
//#define CAN(a,b) memset(a,b,sizeof(a));
//#define MAX_N
//int main()
//{
//
//    while(scanf("")!=EOF)
//    {
//
//    }
//return 0;
//}
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    int m,k;
    while(scanf("%d",n)!=EOF)
    {
        k = 12; m = n % k;
        printf("%d\n",m);
    }
    return 0;
}

