#include<stdio.h>
#include<string.h>
char a[1002],b[1002];
int sum[1002];
int max(int a,int b)
{return a>b?a:b;}
int main()
{
    int t,m,n,i,j,p,s=0;
    while (scanf("%s%s",a,b)!=EOF)
	//scanf("%d",&t);
    //while(t--)
    {
        //scanf("%s%s",a,b);
		//if(a[0]=='0'&&b[0]=='0')
			//break;
        m=strlen(a);
        n=strlen(b);
        for(i=m-1;i>=0;i--)
        {
            sum[m-1-i]+=a[i]-'0';
        }
        for(i=n-1;i>=0;i--)
        {
            sum[n-1-i]+=b[i]-'0';
        }
        p=max(m,n);
        for(i=0;i<=p;i++)
        {
            if(sum[i]>=10)
            {
                sum[i]-=10;
                sum[i+1]++;
            }
        }
        for(j=1002;;j--)
        {
            if(sum[j])
            {
                break;
            }
        }
         printf("Case %d:\n%s + %s = ",++s,a,b);    
         for(i=j;i>=0;--i)
        {
            printf("%d",sum[i]);
        }
        printf("\n");
		for(i=0;i<1002;i++)
		sum[i]=0;
		putchar('\n');
    }
    return 0;
}