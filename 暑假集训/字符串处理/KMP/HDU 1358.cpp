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
int nexts[MAXN];
/**
 *�ַ���Ŵ�0��ʼ����ôif(i%(i-next[i])==0)����iǰ���
 *��Ϊһ���ֻش��������ֻ��Ӵ�����i/(i-next[i])�Ρ�
 */
char x[MAXN];
int main(){
	int T,cas = 0,n;
	while(~scanf("%d",&n)&&n){
		scanf("%s",x);
		printf("Test case #%d\n",++cas);
		int len  = strlen(x); //һ��ʼ��������ѭ���ж��� ÿ��ѭ����Ҫ����һ���˷���ʱ�� �����TLE����������
		kmp_pre(x,len,nexts);
		for(int i=2;i<=len;i++){
			if(i%(i-nexts[i])==0 && i/(i-nexts[i])>1)
				printf("%d %d\n",i,i/(i-nexts[i]));
		}
		putchar('\n');
	}
	return 0;
}
