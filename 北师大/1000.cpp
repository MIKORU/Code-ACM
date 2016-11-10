#include <cstdio>
#include <cstring>
using namespace std;
int n;
char str[1005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int ans = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",str);
            if(str[0]=='b'&&str[1]=='n'&&str[2]=='u'&&str[3]=='1'){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
