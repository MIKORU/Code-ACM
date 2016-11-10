#include <cstdio>
#include <cstring>
#define Max 101
void mult(char a[],char b[],char s[])
{
    int i,j,k = 0,alen,blen,sum = 0,res[65][65]= {0},flag = 0;
    char result[65];
    alen = strlen(a);
    blen = strlen(b);
    for(i = 0; i<alen; i++)
    {
        for(j = 0; j<blen; j++)
            res[i][j] = (a[i]-'0')*(b[j]-'0');
    }
    for(i = alen-1; i>=0; i--)
    {
        for(j = blen-1; j>=0; j--)
            sum = sum+res[i+blen-j-1][j];
        result[k] = sum%10;
        k++;
        sum = sum/10;
    }
    for(i = blen-2; i>=0; i--)
    {
        for(j = 0; j<=i; j++)
            sum = sum+res[i-j][j];
        result[k] = sum%10;
        k++;
        sum = sum/10;
    }
    if(sum)
    {
        result[k] = sum;
        k++;
    }
    for(i = 0; i<k; i++)
        qresult[i]+='0';
    for(i = k-1; i>=0; i--)
        s[i] = result[k-1-i];
    s[k] = '\0';
    while(1)
    {
        if(strlen(s)!=strlen(a) && s[0] == '0')
            strcpy(s,s+1);
        else
            break;
    }
}
void bigNumAdd(char a[],char b[],char sum[])
{
    int i=0;
    int c=0;//表示进位
    char m[Max]= {0};
    char n[Max]= {0};
    memset(sum,0,Max*sizeof(char));
    int lenA=strlen(a);
    int lenB=strlen(b);
    for (i=0; i<lenA; i++)
        m[i]=a[lenA-i-1]-'0';
    for (i=0; i<lenB; i++)
        n[i]=b[lenB-i-1]-'0';
    for (i=0; i<lenA||i<lenB; i++)
    {
        sum[i]=(m[i]+n[i]+c)%10+'0';
        c=(m[i]+n[i]+c)/10;
    }
}
void print(char sum[])
{
    int i=0;
    int j=0;
    int len = strlen(sum);
    for (i=len-1; sum[i]==0; i--);
    for (j=i; j>=0; j--)
        printf("%c",sum[j]);
    putchar('\n');
}
int main()
{
    char c[1000],t[1000],sum[1000],mul[1000];
    int m;
    while(~scanf("%s%s",c,t))
    {
        bigNumAdd(c,t,mul);
        mult(c,t,sum);
        print(mul);
        printf("%s\n",sum);
    }
    return 0;
}
