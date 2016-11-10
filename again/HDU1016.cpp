#include<cstdio>
#include<cstring>
int vis[25];
int a[25];
int n;
int flag = 1;
int is_prime(int x){
	if(x == 2||x==3)
	return 1;
	for(int i=2;i*i<=x;i++){  //这个等于。。我都不想说话了 
		if(x%i==0)
		return 0;
	}
	return 1;
}
void dfs(int x){                                                                                                                                                                                                                                                                                                                                                  
	if(x == n+1 &&is_prime(a[n]+a[1])){
		printf("1");
		for(int i=2;i<=n;i++){
			printf(" %d",a[i]);
		}
		printf("\n");
		return ;
	}
	
	for(int i=2;i<=n;i++){
		if(!vis[i]&&is_prime(i+a[x-1])){
				vis[i] = 1;
				a[x] = i;
				dfs(x+1);
				vis[i] = 0;
			}
	}
}
int main(){
	int T=0;
	while(~scanf("%d",&n)){
		T++;
		memset(vis,0,sizeof(vis));
		printf("Case %d:\n",T);
		a[1] = 1;
		vis[1] = 1;
		dfs(2);
		printf("\n");
	}
	return 0;
} 
