#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100010;
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
int nexts[MAXN];
//x��y�г��ֵĴ���
int KMP_Count(char x[],int m,char y[],int n){//xģʽ�� y����
	int i,j;
	int ans = 0;
	kmp_pre(x,m,nexts);
	i = j = 0;
	while(i<n){
		while(-1!=j && y[i]!= x[j])
			j = nexts[j];
		i++;
		j++;
		if(j >= m){
			ans++;
			j = nexts[j];
		}
	}
	return ans;
}
//������������������
char x[MAXN];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",x);
		kmp_pre(x,strlen(x),nexts);
		int l = strlen(x) - nexts[strlen(x)];  //���ڳ�
		printf("%d\n",nexts[strlen(x)]?(strlen(x)%l?l-strlen(x)%l:0):strlen(x));//strlen(x)%l ��ʾ��һ��ʣ�µ�����
	}
	return 0;
}
