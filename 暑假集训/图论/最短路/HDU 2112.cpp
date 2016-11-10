#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;
const int pathn = 155;
int N;
int d[pathn+10],cost[pathn+10][pathn+10];
bool used[pathn+10];

void init(){
	int i,j;
	for(int i=0;i<=pathn;i++)
		for(int j=0;j<=pathn;j++)
			cost[i][j] = INF;
}
void dijkstra(int s,int V){ //s表示起点 V表示顶点数
	fill(d,d+V,INF);
	fill(used,used+V,false);

	//对d[i]要有初始化
	for(int i=1;i<=V;i++){
		d[i] = cost[s][i];
	}
	d[s] = 0;
	used[s] = 1;
	while(true){
		int v ,mins = INF;
		for(int i=1;i<=V;i++){//d[i]表当前点距离
			if(!used[i] && d[i] < mins)
				mins = d[i],v = i;
		}
		if(mins == INF) break;
		used[v] = true;
		for(int i=1;i<=V;i++){//当前点到其他顶点的距离
			if(!used[i]){
				d[i] = min(d[i],d[v]+cost[v][i]);
			}
		}
	}
}
int main(){
	string start,ends;
	string s,e;
    int t;
    map<string,int >path;
	while(cin>>N&&N!=-1){
        int flag = 0;
		path.clear();
		init();
		cin>>start>>ends;
		if(start == ends){
            flag = 1;
		}
		path[start] = 1;
		path[ends] = 2;
		int num = 3;
		for(int i=0;i<N;i++){
			cin>>s>>e>>t;
			if(!path[s])
				path[s] = num++;
			if(!path[e])
				path[e] = num++;
            if(t < cost[path[s]][path[e]])
                cost[path[s]][path[e]] = cost[path[e]][path[s]] = t;
		}
		if(flag){  //要标记到输入完整才可以666！！！
            cout<<"0\n";
            continue;
		}
		dijkstra(1,num);
		if(d[2] == INF) cout<<"-1\n";
		else cout<<d[2]<<"\n";
	}
	return 0;
}
