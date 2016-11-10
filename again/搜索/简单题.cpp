#include<cstdio>
char a[50];
int vis[50];
void dfs(int cur){
	if(cur == 5){
		for(int i=0;i<5;i++){
			printf("%d",a[i]);
		}
		printf("\n");
	}
	else
	for(int i=0;i<=1;i++) 
	if(!vis[cur]){
		vis[cur] = 1;
		a[cur] = i;
		dfs(cur+1);
		vis[cur] = 0;
	}
}
int main(){
	dfs(0);
	return 0;
}
