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
			for(i=1;i<MAX;i++)		//��ʼ���ٶ�ÿ����ֻ��ʶ�Լ�
				f[i] = i;

			while(m--)
			{
				scanf("%d%d",&a,&b);
				merge(a,b);		//����ab��������ʶ���ϲ���һͬһ����
			}
			for(i=1;i<=n;i++)
			{ 				//�ж��ж��ٸ����Ͼ����ж���Ⱥ���໥��ʶ�����ж�������
				if( f[i] == i )
					res++;		//�жϼ�����Ŀ�Ǹ��ݸ��ڵ�ָ���Լ�
			}
			printf("%d\n",res);

	}
	return 0;
}
