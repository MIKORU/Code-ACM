#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000+5;
int Matrix[maxn][maxn];
int x[maxn],y[maxn],xa[maxn],ya[maxn];
int n,m,q,a,x1,y1;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&Matrix[i][j]);
                y[j] = j;
                ya[j] = 0;
            }
            x[i] = i;
            xa[i] = 0;
        }
        while(q--){
            scanf("%d%d%d",&a,&x1,&y1);
            switch(a){
                case 1:
                    swap(x[x1],x[y1]);
                    //printf("swap(x[x1],x[y1]):%d %d\n",x[x1],x[y1]);
                    break;
                case 2:
                    swap(y[x1],y[y1]);
                    //printf("swap(y[x1],y[y1]):%d %d\n",y[x1],y[y1]);
                    break;
                case 3:
                    xa[x[x1]] += y1;
                    //printf("xa[x[x1]] += y1:%d %d\n",x[x1],xa[x[x1]]);
                    break;
                case 4:
                    ya[y[x1]] += y1;
                    //printf("ya[y[x1]] += y1:%d %d\n",y[x1],ya[x[x1]]);
                    break;
            }
        }
        for(int i=1;i<=n;i++){
            int r = x[i];
            for(int j=1;j<m;j++){
                int c = y[j];
                printf("%d ",Matrix[r][c]+xa[r]+ya[c]);
                //printf("\n%d %d %d %d\n",r,c,xa[r],ya[c]);
            }
            printf("%d\n",Matrix[r][y[m]]+xa[r]+ya[y[m]]);
        }
    }
    return 0;
}
