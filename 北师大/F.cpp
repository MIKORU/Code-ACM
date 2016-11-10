#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <bitset>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const int MX = 5e2 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

LL dp[MX][MX], A[MX];
int main() {
    int T, n, m; //FIN;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%lld", &A[i]);
        }
        sort(A + 1, A + 1 + n);
        memset(dp, INF, sizeof(dp));

        for(int i = 0; i <= m; i++) dp[i][0] = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
                for(int k = 0; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + (A[j] - A[k + 1]) * (A[j] - A[k + 1]));
                }
            }
        }
        printf("%lld\n", dp[m][n]);
    }
    return 0;
}
