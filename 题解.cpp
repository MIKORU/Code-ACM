
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#define INF 0x3f3f3f
#define eps 1e-8
#define MAXN (100000+10)
#define MAXM (100000)
#define Ri(a) scanf("%d", &a)
#define Rl(a) scanf("%lld", &a)
#define Rf(a) scanf("%lf", &a)
#define Rs(a) scanf("%s", a)
#define Pi(a) printf("%d\n", (a))
#define Pf(a) printf("%.2lf\n", (a))
#define Pl(a) printf("%lld\n", (a))
#define Ps(a) printf("%s\n", (a))
#define W(a) while(a--)
#define CLR(a, b) memset(a, (b), sizeof(a))
#define MOD 1000000007
#define LL long long
#define lson o<<1, l, mid
#define rson o<<1|1, mid+1, r
#define ll o<<1
#define rr o<<1|1
using namespace std;
char s[MAXN], str[MAXN*2];
char a[MAXN*2], b[MAXN*2];
bool judge(char op){
    return op != ',' && op != ';';
}
bool check(char op){
    return (op >= 'a' && op <= 'z') || (op >= 'A' && op <= 'Z') || (op == ' ') || (op == '.');
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%s", s) != EOF)
    {
        int len = strlen(s), l;
        if(len == 1 && (s[0] == ';' || s[0] == ','))
        {
            printf("-\n");
            printf("%c,%c\n", 34, 34);
            continue;
        }
        int top = 0;
        for(int i = 0; i < len; i++)
        {
            if(i == 0)
            {
                if(s[i] == ',' || s[i] == ';')
                {
                    str[top++] = ' ';
                    str[top++] = s[i];
                    if(s[i+1] == ',' || s[i+1] == ';')
                        str[top++] = ' ';
                }
                else
                    str[top++] = s[i];
            }
            else if(i == len-1)
            {
                if(s[i] == ',' || s[i] == ';')
                {
                    str[top++] = s[i];
                    str[top++] = ' ';
                }
                else
                    str[top++] = s[i];
            }
            else
            {
                if((s[i] == ',' || s[i] == ';') && (s[i+1] == ',' || s[i+1] == ';'))
                {
                    str[top++] = s[i];
                    str[top++] = ' ';
                }
                else
                    str[top++] = s[i];
            }
        }
        str[top] = '\0';
        a[0] = b[0]= '"'; a[1] = b[1] = '\0';
        int timea = 0, timeb = 0;
        for(int i = 0; i < top; )
        {
            if(judge(str[i]))
            {
                int j = i; int k = 0; bool flag = true;
                while(j < top && judge(str[j]))
                {
                    if(check(str[j]))
                        flag = false;
                    s[k++] = str[j++];
                }
                s[k] = '\0';
                if(s[0] == '0' && k > 1)
                    flag = false;
                if(flag)
                {
                    if(timea)
                    {
                        l = strlen(a);
                        a[l] = ',';
                        a[l+1] = '\0';
                    }
                    if(s[0] != ' ')
                        strcat(a, s);
                    timea++;
                }
                else
                {
                    if(timeb)
                    {
                        l = strlen(b);
                        b[l] = ',';
                        b[l+1] = '\0';
                    }
                    if(s[0] != ' ')
                        strcat(b, s);
                    timeb++;
                }
                i = j+1;
            }
        }
        if(timea == 0)
            printf("-\n");
        else
        {
            printf("%s", a);
            printf("%c\n", 34);
        }
        if(timeb == 0)
            printf("-\n");
        else
        {
            printf("%s", b);
            printf("%c\n", 34);
        }
    }
    return 0;
}

