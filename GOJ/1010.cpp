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
1: ����Ϊ1, ��βΪ1
2: ����Ϊ4, ��βΪ2 4 8 6
3: ����Ϊ4, ��βΪ3 9 7 1
4: ����Ϊ2, ��βΪ4 6
5: ����Ϊ1, ��βΪ5
6: ����Ϊ1, ��βΪ6
7: ����Ϊ4, ��βΪ7 9 3 1
8: ����Ϊ4, ��βΪ8 4 2 6
9: ����Ϊ2, ��βΪ9 1
0: ����Ϊ1, ��βΪ0 
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

