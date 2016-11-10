#include<iostream>
#include<cstdio>
#include<vector> 
#include<algorithm>
using namespace std;
const int MAXN = 1000010;
typedef vector<int> Vec;
void Print(Vec &c){
	for(int i=0;i<c.size()-1;i++){
		cout<<c[i]<<" ";
	}
	cout<<c[c.size()-1]<<endl;
}
int main(){
	int n,m;
	while(cin>>n>>m){
		Vec a,b,c;
		for(int i=0;i<n;i++){
			int num;
			cin>>num;
			a.push_back(num);
		}
		for(int i=0;i<m;i++){
			int num;
			cin>>num;
			b.push_back(num);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		set_intersection(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));
		Print(c);
		c.clear();
	}
}
