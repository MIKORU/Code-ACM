#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n;
	int p[10];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		p[i] = i;
	}
	do{
		for(int i=0;i<n;i++){
			printf("%d ",p[i]);
		}
		printf("\n");
	}while(next_permutation(p,p+n));
	return 0;
} 
