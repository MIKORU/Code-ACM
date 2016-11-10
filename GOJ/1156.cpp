//#include<iostream>
//#include <cstdio>
//#include<algorithm>
//using namespace std;
//int st[100000];
//int end[100000];
//int main(){
////    freopen("00.txt","r",stdin);
////    freopen("01.txt","w",stdout);
//    int cas,res,min,max,j1,j2,r,n,i;
//    while(cin >> n){
//        min = 1000000001;
//        max = 0;
//        for(i = 0;i < n;i++){
//            cin >> st[i] >> end[i];
//            if(st[i] < min)
//                min = st[i];
//            if(end[i] > max)
//                max = end[i];
//        }
//        sort(st,st + n);
//        sort(end,end + n);
//        r = res = j1 = j2 = 0;
//        for(i = min;i <=max;){
//            if(i == st[j1])
//            {j1++;r++;}
//            if(i == end[j2])
//            {j2++;r--;}
//            if(r > res)
//                res = r;
//            if(j1 < n && j2 < n)
//                i = (end[j2] < st[j1] ? end[j2] : st[j1]);
//            else if(j1 < n && j2 >= n)
//                i = st[j1];
//            else if(j2 < n && j1 >= n)
//                i = end[j2];
//            else break;
//        }
//        cout << res << endl;
//    }
//    return 0;
//}
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int ,int >P;
P a[100];
int main()
{
    freopen("00.txt","r",stdin);
    freopen("01.txt","w",stdout);
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>a[i].first>>a[i].second;
        sort(a,a+n);
        int ans = 1;
        for(int i=0;i<n;i++)
            if(a[i].first == a[i+1].first)
                ans+=2;
        cout<<ans<<endl;
    }
    return 0;
}
