#include<stdio.h>
double a[22],b[22];  //a[]存放错排数，b[]存放阶乘数
void fum()
{
    int  i;
    a[1]=0;
    a[2]=1;
    for(i=3;i<=20;i++)
        a[i]=(i-1)*a[i-1];
    b[0]=1;
    b[1]=1;
    b[2]=2;
    for(i=3;i<=20;i++)
        b[i]=i*b[i-1];
    //for(i=1;i<=20;i++)
//    printf("%.lf         %.lf\n",a[i],b[i]);

}
double cc(int a,int b)   //求组合的函数
{
    int i;
    double sum=1;
   if(b==0)return 1;
    if(b>a/2)b=a-b;
    for(i=1;i<=b;i++)
        sum*=a-i+1;
    for(i=1;i<=b;i++)
        sum/=i;
    return sum;
}
int main()
{
    int T, cas,n,k;
      int i;
      double s,zu;
    fum();
    scanf("%d",&T);
    while(T--)
    {
        s=0;
        scanf("%d%d%d",&cas,&n,&k);
        if(k==1)s=b[n-1];
        else
            if(k==2)s=b[n-2];
        else
        {
           s=b[n-2];
           for(i=3;i<=k;i++)
           {
               zu=cc(k-2,k-i);
               s+=b[n-i]*a[i]*zu;
           }
        }
        printf("%d %.lf\n",cas,s);
    }
    return 0;
}
