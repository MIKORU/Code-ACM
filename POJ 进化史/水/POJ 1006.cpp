//132K	63MS
//�й�ʣ�ඨ���Ӧ�ã�����ѧ�����ˣ�
//http://user.qzone.qq.com/289065406/blog/1309411846
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int Case = 1,P,E,I,S,ans;
    while(scanf("%d%d%d%d",&P,&E,&I,&S)!=EOF)
    {
        if(P==E&&E==I&&I==S&&S==-1)
            break;
        int ans = (5544*P+14421*E+1288*I-S+21252)%21252;
        if(ans==0)
            ans = 21252;
        printf("Case %d: the next triple peak occurs in %d days.\n",Case++,ans);
    }
    return 0;
}
