#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // ȡ����ֵ
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>  //priority_queue<int>
#include <vector>
#include <map>
#include <set>
#include <utility> //pair����� typedef pair<int ,int>P;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a))  //���� memset(a,0x7f,sizeof(a));
#define MAX_N
const int INF = 0x3f3f3f3f;
using namespace std;
int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		if(a>b){
            swap(a,b);
        }
		double k=b-a;
		double x=(1+sqrt(5.0))/2;
		int t=(k*x+k);
		if(t==b)printf("0\n");
		else printf("1\n");
	}
	return 0;
}
