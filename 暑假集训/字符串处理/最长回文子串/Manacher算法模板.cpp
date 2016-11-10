#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = ;
char Ma[MAXN*2];
int Mp[MAXN*2];
void Manacher(char s[],int len){
	int l = 0;
	Ma[l++] = '$';
	MA[l++] = '#';
	for(int i=0;i<len;i++){
		Ma[l++] = s[i];
		Ma[l++] = '#';
	}
	Ma[l] = 0;
	int mx = 0,id = 0;
	for(int i=0;i<l;i++){
		Mp[i] = mx>i?min(Mp[2*id-1],mx-i):1;
		while(Ma[i+Mp[i]]==Ma[i-Mp[i]])
			Mp[i]++;
		if(i+Mp[i]>mx){
			mx = i+Mp[i];
			id = i;
		}
	}
}
char s[MAXN];
int main(){
	while(scanf("%s",s)==1){
		int len = strlen(s);
		Manacher(s,len);
		int ans = 0;
		for(int i=0;i<2*len+2;i++){
			ans = max(ans,Mp[i]-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}