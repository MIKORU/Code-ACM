#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000010;
void kmp_pre(char x[],int m,int next[]){
	int i,j;
	j = next[0] = -1;
	i = 0;
	while(i<m){
		while(-1 != j && x[i] != x[j])
			j = next[j];
        next[++i]= ++j;
	}
}
void preKMP(char x[],int m,int kmpNext[]){
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
int next[MAXN];
//x在y中出现的次数
int KMP_Count(char x[],int m,char y[],int n){//x模式串 y主串
	int i,j;
	int ans = 0;
	kmp_pre(x,m,next);
	i = j = 0;
	while(i<n){
		while(-1!=j && y[i]!= x[j])
			j = next[j];
		i++;
		j++;
		if(j >= m){
			ans++;
			j = next[j];
		}
	}
	return ans;
}
char x[MAXN];
char y[MAXN];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",x,y);
        printf("%d\n",KMP_Count(x,strlen(x),y,strlen(y)));
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
    }
    return 0;
}
