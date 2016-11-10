#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<iostream>
using namespace std;
#define N 10005
char z[N*N];
int main()
{
    int a[10]={6,2,4,8},b[10]={1,3,9,7},c[10]={6,4,6,4};
    while(gets(z))
    {
        //memset(z,0,sizeof(z));
        int l=strlen(z);
        int w;
        if(z[l-2]=='0'||l==1) w=z[l-1]-'0';
        else w=z[l-1]-'0'+(z[l-2]-'0')*10;
        w%=4;
        printf("%d\n",(1+a[w]+b[w]+c[w])%5);
    }
	return 0;
}
