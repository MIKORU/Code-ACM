#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MAXV 10000

bool prime[MAXV];

void init(){
	int i,j;
	for(i=1000;i<=MAXV;i++){
		for(j=2;j<i;j++)
			if(i%j==0){
				prime[i]=false;
				break;
			}
		if(j==i) prime[i]=true;
	}
}

int bfs(int first,int last){
	bool dis[MAXV];
	queue <int>q;
	int v,i,j,temp,vtemp,count[MAXV],t[4];
	memset(dis,false,sizeof(dis));
	memset(count,0,sizeof(count));

	q.push(first);
	dis[first]=true;

	while(!q.empty()){
		v=q.front();
		q.pop();

		t[0]=v/1000;
		t[1]=v%1000/100;
		t[2]=v%100/10;
		t[3]=v%10;
		for(j=0;j<4;j++){
			temp=t[j];
			for(i=0;i<10;i++)
				if(i!=temp){
					t[j]=i;
					vtemp=t[0]*1000+t[1]*100+t[2]*10+t[3];
					if(!dis[vtemp] && prime[vtemp]){
						count[vtemp]=count[v]+1;
						dis[vtemp]=true;
						q.push(vtemp);
					}
					if(vtemp==last) return count[vtemp];
				}
			t[j]=temp;
		}
		if(v==last) return count[v];
	}
	return -1;
}

int main(){
	int n,a,b,key;
	init();
	while(scanf("%d%d",&a,&b)){
		if(!prime[b]){
            printf("AC\n");
            continue;
		}
		key=bfs(a,b);
		if(key!=-1) printf("%d\n",key);
		else printf("AC\n");
	}
	return 0;
}
