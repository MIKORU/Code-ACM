#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#define MAXN 105000
#define MAXP 1000050
const int INF = -0xfffffff;
//218MS 这题太水 不说
using namespace std;
int a;
int p[MAXP];
int main()
{
	int N;
	while(~scanf("%d",&N)){
		memset(p,0,sizeof(p));
		for(int i=0;i<N;i++){
			scanf("%d",&a);
			p[a]++;
		}
		for(int i=0;;i++){
			if(p[i]>=(N+1)/2){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
