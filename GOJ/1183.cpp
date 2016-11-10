#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 4000;
int n, m, G[maxn][maxn], c[maxn], t;
bool dfs(int u){
  c[u] = -1;
  for(int v = 0; v < n; v++) if(G[u][v]) {
    if(c[v]<0) return false;
    else if(!c[v]) dfs(v);
  }
  c[u] = 1;
  return true;
}
bool toposort(){
  t = n;
  memset(c, 0, sizeof(c));
  for(int u = 0; u < n; u++) if(!c[u])
    if(!dfs(u)) return false;
  return true;
}
int main() {
100 4
1 2
3 4
3 5
4 5
//    freopen("00.txt","r",stdin);
//    freopen("01.txt","w",stdout);
  while(scanf("%d%d", &n, &m) == 2 && n) {
    memset(G, 0, sizeof(G));
    for(int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &v, &u);
      u--; v--;
      G[u][v] = 1;
    }
    if(toposort()) {
        printf("Yes\n");
    }
    else
        printf("No\n");
  }
  return 0;
}
