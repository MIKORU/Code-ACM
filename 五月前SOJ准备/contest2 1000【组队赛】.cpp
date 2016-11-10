//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h> // 取绝对值
//#include <iostream>
//#include <algorithm>
//#include <stack>
//#include <queue>  //priority_queue<int>
//#include <vector>
//#include <map>
//#include <set>
//#include <utility> //pair类或者 typedef pair<int ,int>P;
//#define LL long long
//#define CAN(a,b) memset(a,b,sizeof(a))  //大数 memset(a,0x7f,sizeof(a));
//#define MAX_N 100000
//const int INF = 0x3f3f3f3f;
//using namespace std;
//struct node
//{
//    int x;
//    float y;
//}a[MAX_N];
//bool cmp(node a,node b)
//{
//    if(a.y==b.y)
//        return a.x<b.x;
//    return a.y>b.y;
//}
//int main()
//{
//
//    int n,c,m,s,T;
//    float t;
//    scanf("%d",&T);
//    while(T--)
//    {
//        scanf("%d%d%d",&n,&c,&m);
//        for(int i=0;i<n;i++)
//            {
//                scanf("%d%f",&a[i].x,&t);
//                a[i].y = t/100;
//            }
//        sort(a,a+n,cmp);
//        float ans = 1;
//        s=0;
//        for(int i=0;i<c;i++)
//        {
//            if(s<m)
//            {
//                s +=a[i].x;
//                ans *= a[i].y;
//            }
//        }
//        printf("%g\n",ans);
//    }
//return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <map>
//using namespace std;
//int n;
//int main()
//{
//    int T;
//
//    cin>>T;
//	while(T--)
//    {
//        map<string ,int >p;
//        cin >> n;
//        int ans = 1;
//        for (int i=0; i<n; i++)
//        {
//            string str[2];
//            cin >> str[0] >> str[1];
//            p[str[1]]++;
//        }
//        for(map<string,int>::iterator iter=p.begin();iter!=p.end();iter++)
//        {
//            ans*=(iter->second+1);
//        }
//        cout<<ans-1<<endl;
//    }
//	return 0;
//}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>  //priority_queue<int>
#include <vector>
#include <map>
#include <set>
#include <utility> //pair类或者 typedef pair<int ,int>P;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a))  //大数 memset(a,0x7f,sizeof(a));
#define MAX_N 100000
const int INF = 0x3f3f3f3f;
using namespace std;
string a[MAX_N];
int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        map<char , char>p;
        cin>>n;
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            for(int j=0;j<a[i].length();j++)
                p[a[i][j]]=a[n][j];
    }
    return 0;
}
