#include <cstdio>
using namespace std;
int main()
{
    int t,i;
    while(scanf("%d",&t)!=EOF&&t)
    {
        if(((t+1)&t)==0)
            printf("Bob\n");
        else printf("Alice\n");
    }
    return 0;
}
