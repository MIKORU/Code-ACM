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
 *字符编号从0开始，那么if(i%(i-next[i])==0)，则i前面的
 *串为一个轮回串，其中轮回子串出现i/(i-next[i])次。
 */
char x[MAXN];
int main(){
	int T,cas = 0,n;
	while(~scanf("%d",&n)&&n){
		scanf("%s",x);
		printf("Test case #%d\n",++cas);
		int len  = strlen(x); //一开始把他放在循环判断上 每次循环都要运行一次浪费了时间 结果就TLE滚滚滚！！
		kmp_pre(x,len,nexts);
		for(int i=2;i<=len;i++){
			if(i%(i-nexts[i])==0 && i/(i-nexts[i])>1)
				printf("%d %d\n",i,i/(i-nexts[i]));
		}
		putchar('\n');
	}
	return 0;
}
