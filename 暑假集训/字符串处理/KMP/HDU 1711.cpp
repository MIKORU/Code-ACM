#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int nexts[10000100];
int a[1000010];
int b[1000010];
int flag = 0;
void kmp_pre(int x[],int m,int nexts[]){
	int i,j;
	j = nexts[0] = -1;
	i = 0;
	while(i<m){
		while(-1 != j && x[i] != x[j])
			j = nexts[j];
        nexts[++i]= ++j;
	}
}
void preKMP(int x[],int m,int kmpNext[]){
	int i,j;
	j = kmpNext[0] = -1;
	i = 0;
	while(i<m){
		while(-1 != j && x[i] != x[j])
			j = kmpNext[j];
		if(x[++i] == x[++j])
			kmpNext[i] = kmpNext[j];
		else
			kmpNext[i] = j;
	}
}

//x在y中出现的次数
int KMP_Count(int x[],int m,int y[],int n){//x模式串 y主串
	int i,j;
	int ans = 0;
	kmp_pre(x,m,nexts);
	i = j = 0;
	while(i<n){
		while(-1!=j && y[i]!= x[j])
                j = nexts[j];
		i++;
		j++;
		if(j == m){
            return i-m+1;
		}
	}
	return -1;
}
int main(){
	int N,M,T;
    scanf("%d",&T);
    while(T--){
        flag = 0;
    	scanf("%d%d",&N,&M);
    	for(int i=0;i<N;i++){
    		scanf("%d",&a[i]);
    	}
    	for(int i=0;i<M;i++){
    		scanf("%d",&b[i]);
    	}
    	printf("%d\n",KMP_Count(b,M,a,N));
    }
    return 0;
}
