#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 105;
int N,M;
char maps[maxn][maxn];
int father[maxn*maxn*2];
int getfather(int x)
{
    if(x==father[x])
        return x;
    father[x] = getfather(father[x]);
}
void merges(int a,int b)
{
    a = getfather(a);
    b = getfather(b);
    if(a!=b)
        father[a] = b;
}
bool check(int a,int b)
{
    a = getfather(a);
    b = getfather(b);
    return a==b;
}
void init()
{
    for(int i=1;i<=2*N*M;i++)
        father[i] = i;
}
int get(int x,int y)
{
    return (x-1)*M+y;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++){
            scanf("%s",maps[i]);
        }
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++)
                printf("%c",maps[i][j]);
        init();
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                int L = get(i,j);
                if(j<M){
                    int Rx = get(i,j+1);
                    merges(2*L,2*Rx-1);
                }
                if(i<N){
                    int Ry = get(i+1,j);
                    if(maps[i][j]=='R'&&maps[i+1][j]=='L') merges(2*L-1,2*Ry-1);
                    if(maps[i][j]=='R'&&maps[i+1][j]=='R') merges(2*L-1,2*Ry);
                    if(maps[i][j]=='L'&&maps[i+1][j]=='R') merges(2*L,2*Ry);
                    if(maps[i][j]=='L'&&maps[i+1][j]=='L') merges(2*L,2*Ry-1);
                }
            }
        }
        for (int i=1;i<=M;i++){
            for (int j=1;j<=M;j++){
                int L=(maps[1][i]=='L')?2*get(1,i)-1:2*get(1,i);
                int R=(maps[N][j]=='R')?2*get(N,j)-1:2*get(N,j);
                if (check(L,R)){
                    printf("Yes\n");
                    continue;
                }
            }
        }
        printf("No\n");

    }
    return 0;
}
