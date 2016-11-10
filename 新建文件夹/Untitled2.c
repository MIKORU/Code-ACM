#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define INF 0x3f3f3f3f

int main()
{
    char s[205],b[205];
    int c[205];
    int i,j,k,len;
    while(scanf("%s",s)!=EOF)
    {
        len=strlen(s);
        j=0;
        k=0;
        for(i=len-1;i>=0;i--)
        {
            if(s[i]<'0'||s[i]>'9')
                break;
            c[k++]=s[i]-'0';
        }

        for(i=0;i<len-k;i++)
            printf("%c",s[i]);
            if(k==0)
        {
            printf("1\n");
            continue;
        }
        c[0]++;
        c[k]=100;
        for(i=0;i<k;i++)
        {
            if(c[i]>=10){
            c[i]-=10;
            c[i+1]++;}
        }
        if(c[k]==101)
            printf("%d",1);
        for(i=k-1;i>=0;i--)
            printf("%d",c[i]);
            printf("\n");
        /*k=1;
        c[0]=100;
        for(;i<len;i++)
        {
            c[k++]=s[i]-'0';
        }
        for(i=0;i<j;i++)
            printf("%c",b[i]);
        c[k-1]++;
        for(i=k-1;i>0;i--)
        {
            if(s[i]>=10)
                s[i]-=10;
            s[i-1]++;
        }
        if(c[0]==101)
            printf("1");
        for(i=1;i<k;i++)
            printf("%d",c[i]);

        /*for(i=len-1;i>=0;i--)
        {
            if(s[len-1]<'0'||s[len-1]>'9')
            {
                s[len]=1;
                len++;
                break;
            }
            s[i]+=1;
            if(s[i]>'9')
            {
                s[i]=0;
                s[i-1]+=1;
            }
        }
        for(i=0;i<len;i++)
            printf("%c",s[i]);
        printf("\n");*/
    }
}
