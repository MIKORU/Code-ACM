#include<stdio.h>
#include<string.h>
int main()
{
    char a[105],c[105];
    int i,j,m,flag;
    while(scanf("%s",&a)!=EOF)
    {
        m=strlen(a);
        if(a[0]=='0'&&m==1) {printf("0\n");continue;}
        flag=0;
        for(i=0,j=0;a[i]!='.';i++)
        {

            if(a[i]!='0'&&a[i]!='-'||flag==1)
            {c[j++]=a[i];flag=1;}

        }
        if(flag==0)
            {c[j++]='0';}
        c[j++]='.';
        for(i=i+1;;i++)
        {
            c[j++]=a[i];
            if(a[i]!='0'&&a[i+1]=='0')break;
        }
        c[j++]='\0';
        if(a[0]=='-')
            printf("%s\n",c);
        else printf("-%s\n",c);
    }
    return 0;
}
