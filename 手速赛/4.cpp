#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define N 210
int A[N],B;
void cv(int x)
{
	int c = 0;
	while (x)
	{
		if(x%B<10)
			A[c++] = x%B+'0';
		else
			A[c++] = x%B-10+'a';
		x/=B;
	}
	A[c]='\0';
}
int main()
{
    int n,C[N],s;
    while(scanf("%d%d",&n,&B)!=EOF)
    {
        while(n--)
        {
            scanf("%d",&s);
            cv(s);
            printf("%s\n",A);

        }

    }

return 0;
}
