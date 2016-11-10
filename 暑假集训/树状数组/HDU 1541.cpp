#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 32010;
int light[MAXN+10000];
int bit[MAXN];
int n;
int lowbit(int t){
	return t&(-t);
}
void update(int k){
	while(k<=MAXN){
		bit[k] ++;
		k += lowbit(k);
//		printf("bit[%d] = %d\n",k,bit[k]);
	}
}
int sum(int k){
	int s = 0;
	while(k > 0){
		s += bit[k];
		k -= lowbit(k);
	}
	return s;  //错这里半天木有反应过来啊啊啊！！！
}
int main(){
	while(~scanf("%d",&n)){
		memset(light,0,sizeof(light));
		memset(bit,0,sizeof(bit));
		for(int i=0;i<n;i++){
		    int x,y;
			scanf("%d%d",&x,&y);
			light[sum(x+1)]++;  //前进一位的x
			update(x+1);
		}
		for(int i=0;i<n;i++)
			printf("%d\n",light[i]);
	}
	return 0;
}
