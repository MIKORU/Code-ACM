#include <stdio.h>
#include <algorithm>
#include <string.h>
#define N 1005
using namespace std;
struct node
{
        int len;
        char name[15];
} a[N];
bool cmp(node a, node b)
{
    int i;
    if(a.len > b.len) return true;
    if(a.len < b.len) return false;
    for(i=0;i<10;i++)
    {
        if(a.name[i]==b.name[i]) continue;
        if(a.name[i]<b.name[i]) return true;
        else return false;
    }

}
int main()
{
    int n,b[15],i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",&a[i].name);
            a[i].len=strlen(a[i].name);
        }
        sort(a,a+n,cmp);
        for(i=0;i<n;i++)
            printf("%s\n",a[i].name);
    }
    return 0;
}
