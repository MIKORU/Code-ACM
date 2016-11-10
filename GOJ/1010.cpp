#include <stdio.h>
/*int p(int x,int y)
{
	int i,t=1;
	for(i=0;i<y;i++)
		t*=x;
	return t;
}
int main()
{
	int a,b,c;
	while (scanf("%d%d",&a,&b)!=EOF)
	{
		if(a==0)
			break;
		a=a%10;
		b=b%4;
		c=p(a,b)%10;
		printf("%d\n",c);
	}
return 0;
}*/
/*
1: 周期为1, 结尾为1
2: 周期为4, 结尾为2 4 8 6
3: 周期为4, 结尾为3 9 7 1
4: 周期为2, 结尾为4 6
5: 周期为1, 结尾为5
6: 周期为1, 结尾为6
7: 周期为4, 结尾为7 9 3 1
8: 周期为4, 结尾为8 4 2 6
9: 周期为2, 结尾为9 1
0: 周期为1, 结尾为0 
*/
int main()  
{  
    int a,b;  
    while(scanf("%d%d",&a,&b)!=EOF)  
    {  
        a%=10;  
        if(a==0||a==5||a==6||a==1) printf("%d\n",a);  
        else if(a==4||a==9)  
        {  
            printf("%d\n",b%2==0?a*a%10:a);   
        }  
        else  
        {  
            if(b%4==1) printf("%d\n",a);  
            else if(b%4==2) printf("%d\n",a*a%10);  
            else if(b%4==3) printf("%d\n",a*a*a%10);  
            else printf("%d\n",a*a*a*a%10);   
        }     
    }  
    return 0;     
}  

