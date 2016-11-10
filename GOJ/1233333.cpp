#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int pre[233];
vector<int> get_path(int t){
	vector<int>path;
	for(;t!=-1;t = pre[t]){
		path.push_back(t);
	}
//	reverse(path.begin(),path.end());
	return path;
}
int main()
{
    fill(pre,pre+233,0);
    vector<int>pathw;
    pathw = get_path(1);
    printf("%d\n",pathw[1]);
    return 0;
}
