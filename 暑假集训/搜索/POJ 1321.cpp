//�����Ҫ��էһ�����ѻ������ѣ�ȷʵ��ˣ������֪�������ѵķ����������ͼ�
//�˲��٣����������ѵ�ʱ��Ҫ���ǵ�k==n��k<nʱ�������������K==nʱ����Ȼ�ܺ���
//���������º������ҵ����з����������ǵ�k<nʱ�͵ÿ��Ǻ���������
//���Ժ�����˸�dfs(row+1,num)��Ҫ����������Ŀ��ǡ�
#include <cstdio>
#include <cstring>
using namespace std;
int N,K;
int ans;
char map[10][10];
int vis[10];
void dfs(int h,int n)   //h��ʾ��ǰ�У�n��ʾĿǰ���˼�������
{
    if(n == K){
        ans++;
        return ;
    }
    if(h >= N) return ;  //��ǰ�б߽糬�� ����
    for(int i=0;i<N;i++){  //i��ʾ��
        if(!vis[i]&&map[h][i]=='#'){
            vis[i] = true;
            dfs(h+1,n+1);
            vis[i]=0;   //��һ�㷵�غ� �������ʧ
        }
    }
    dfs(h+1,n);   //��㲻������ ����һ���ٴ��� ��һ����� û���������WA
}
int main()
{
    while(~scanf("%d%d",&N,&K)){
        memset(vis,0,sizeof(vis));
        ans=0;
        if(N==K&&N==-1)
            break;
        for(int i=0;i<N;i++){
            scanf("%s",&map[i]);
        }
        dfs(0,0);
        printf("%d\n",ans);
    }
}
