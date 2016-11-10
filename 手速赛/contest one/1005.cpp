#include<iostream>
#include <string.h>
using namespace std;
#define M 22

int r, c, ans;
bool map[M][M], v[M][M];
int dr[4] = {0, 1, -1, 0};
int dc[4] = {-1, 0, 0, 1};

bool f(int a, int b)
{
    if(a >= 1 && a <= r && b >= 1 && b <= c)
        return  1;
    return  0;
}
void dfs(int nr, int nc)
{
    for(int i = 0; i < 4; i ++){
        int a = nr + dr[i];
        int b = nc + dc[i];
        if(f(a, b) && !v[a][b] && map[a][b]){
            v[a][b] = true;
            ans ++;
            dfs(a, b);
        }
    }
}
int main(){
    int i, j, sr, sc;
    while(1){
        cin >> c >> r;
        if(r == 0 && c== 0)  break;
        for(i = 1; i <= r; i ++)
            for(j = 1; j <= c; j ++){
                char m;
                cin >> m;
                if(m == '.')  map[i][j] = 1;
                else if(m == 'X')  map[i][j] = 0;
                else{
                    map[i][j] = 1;
                    sr = i;
                    sc = j;
                }
            }
        memset(v, 0, sizeof(v));
        v[sr][sc] = 1;
        ans = 1;
        dfs(sr, sc);
        cout << ans << endl;
    }
    return 0;
}
