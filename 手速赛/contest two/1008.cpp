#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // È¡¾ø¶ÔÖµ //
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility> //pair<int int >a[?]
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		long long x;
		scanf("%lld" , &x);
		x -= n + 2;
		int res = 0;
		if (x >= 0)
		{
			if (x < n)
				res = x + 1;
			else
				res = 2 * n - x - 1;
		}
		printf("%d\n" , res);
	}
    return 0;
}

