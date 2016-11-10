 #include<stdio.h>
int main()
 {
    int list[6]={0,50,100,0,0,50};
    int t,n;
    scanf("%d",&t);
    while(t--)
     {
        scanf("%d",&n);
        if(n<300)
            printf("%d\n",n%50+list[n/50]);
         else
             printf("%d\n",n%50);
    }
	return 0;
 }