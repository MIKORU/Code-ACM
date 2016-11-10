#include<cstdio>
#include<cmath>
#include<cstring>
int qian[100];
int flag = 0;
int n;
int main(){
	int T;
	scanf("%d",&T); 
	while(T--){
	scanf("%d",&n);
		int ans = 0;
	//	memset(zhuzi,0,sizeof(zhuzi));
		memset(qian,0,sizeof(qian));
		for(int i=1;;i++){
		flag = 0;
			for(int j=1;j<=n;j++){
				int s = sqrt(qian[j]+i);
				//printf("s=%d\n",s);
				//printf("qian[%d] = %d\n",j,qian[j]);
				if(!qian[j]||s*s ==(qian[j]+i) ){
					flag = 1;
					qian[j] = i;
				//	printf("flag = %d\n",flag);
					break;
					
				}
			}
			if(flag == 0){
				ans = i-1;
				break;
			}
		}
		printf("%d\n",ans);
	}
} 
