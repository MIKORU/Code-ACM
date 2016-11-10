#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 10010;
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
//x��y�г��ֵĴ���
int KMP_Count(char x[],int m,char y[],int n){//xģʽ�� y����
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
			j = i;
		}
	}
	return ans;
}
char x[MAXN];
char y[MAXN];
int main(){
	while(~scanf("%s",y)&&y[0] != '#'){
		scanf("%s",x);
		printf("%d\n",KMP_Count(x,strlen(x),y,strlen(y)));
	}
	return 0;
}
