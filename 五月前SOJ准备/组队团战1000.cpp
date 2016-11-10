#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility> //pair类
#define LL long long
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a))  //大数 memset(a,0x7f,sizeof(a));
#define MAX_N
const int INF = 0x3f3f3f3f;
using namespace std;
int main()
{
    LL a,b,c;
    while(~scanf("%I64d%I64d",&a,&b))
    {
        if(a<=0&&b<=0||a>b)
            c = a-b;
        else c = a+b;
        printf("%I64d\n",c);
    }
    return 0;
}



//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h> // 取绝对值
//#include <iostream>
//#include <algorithm>
//#include <stack>
//#include <map>
//#include <set>
//#include <utility> //pair类
//#define LL long long
//#define LL long long
//#define CAN(a,b) memset(a,b,sizeof(a))  //大数 memset(a,0x7f,sizeof(a));
//#define MAX_N
//const int INF = 0x3f3f3f3f;
//using namespace std;
//int main()
//{
//
//    while(scanf("")!=EOF)
//    {
//
//    }
//return 0;
//}
