#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

int T,N,X;
pair <int,int> hk[100000005];
int flag,ans[100005];

int main()
{
    while (~scanf("%d",&T)){
        X=1;
        while (T--){
            flag=0;
            cin>>N;
            for (int i=1;i<=N;i++){
                cin>>hk[i].first>>hk[i].second;
                if (hk[i].second>(N-i)/2){
                    hk[i].second=(N-i)-hk[i].second;
                }
                if (hk[i].second<0){
                    flag=1;
                }
            }
            if (flag==1){
                cout<<"Case #"<<X++<<": impossible"<<endl;
                continue;
            }
            sort(hk,hk+N);
            memset(ans,0,sizeof(ans));
            ans[hk[1].second+1]=hk[1].first;
            for (int i=1,cnt=0;i<=N;i++){
                if (hk[i].second==0&&ans[i]==0)
                    ans[i]=hk[i].first;
                else if (ans[i]!=0) cnt++;
                else if (hk[i].second==cnt){
                    ans[i]=hk[i].first;
                    cnt=0;
                }
            }
            cout<<"Case #"<<X++<<": ";
            if (ans[N]>ans[1]){
                for (int i=1;i<N;i++){
                    cout<<ans[i]<<" ";
                }
                cout<<ans[N]<<endl;
            }
            else {
                for (int i=N;i>1;i++){
                    cout<<ans[i]<<" ";
                }
                cout<<ans[1]<<endl;
            }
        }
    }
    return 0;
}
