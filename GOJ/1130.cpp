#include<stdio.h>  
#include<string.h>  
int main()
{  
    double ans;  
    char c[50];  
    int n, i,p = 0,m,s;  
    scanf("%d", &n);  
    getchar();
    while(n--)
	{  
        gets(c);  
        ans = 100;  
        m = 0;  
        s = strlen(c);  
        for(i = 0; i < s; i++)
		{  
            if(c[i] == 'B')
			{  
                switch (c[i-1])
			{
				case'K':m = 1;break;
				case'M':m = 2;break;
				case'G':m = 3;break;
				case'T':m = 4;break;
				case'P':m = 5;break;
				case'E':m = 6;break;
				case'Z':m = 7;break;
				case'Y':m = 8;break;
				default:break;
			}
            }   
        }  
        if(m == 0)  
            printf("Case #%d: 0.00%%\n", ++p);  
        else 
		{  
            while(m--)
			{  
                ans *= 1000;  
                ans /= 1024;  
            }  
            ans = 100 - ans;  
            printf("Case #%d: %.2lf%%\n", ++p, ans);  
        }  
    }  
    return 0;  
}  