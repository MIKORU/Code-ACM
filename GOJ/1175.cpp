#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    char s[105];
    scanf("%d",&n);
    getchar();
    while(n--)
    {

        gets(s);
        s[0]=s[0]-'a'+'A';
        for(i=0;i<strlen(s);i++)
            if(s[i]==' ') s[i+1]=s[i+1]-'a'+'A';
        puts(s);
    }
    return 0;
}
