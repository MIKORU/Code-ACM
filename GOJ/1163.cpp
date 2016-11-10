#include<cstdio>
#define MAX 10002
int f[MAX];
int find(int x)
{
	if( x != f[x] )
		f[x] = find(f[x]);
	return f[x];
}
void merge(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x != y)
		f[x] = y;
}
int main()
{
	int i,n,m,t,a,b,res;
//    freopen("00.txt","r",stdin);
//    freopen("01.txt","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
			res = 0;
			for(i=1;i<MAX;i++)		//初始化假定每个人只认识自己
				f[i] = i;

			while(m--)
			{
				scanf("%d%d",&a,&b);
				merge(a,b);		//输入ab，他们认识，合并在一同一集合
			}
			for(i=1;i<=n;i++)
			{ 				//判断有多少个集合就是有多少群人相互认识，就有多少桌子
				if( f[i] == i )
					res++;		//判断集合数目是根据根节点指向自己
			}
			printf("%d\n",res);

	}
	return 0;
}
