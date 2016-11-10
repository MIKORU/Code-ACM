#include <stdio.h>
int leap(int x)
{
	int i=0;
	if(x%4==0&&x%100!=0||x%400==0)
		return 1;
	else
		return 0;
}
int main()
{
	int N,y,s,i;
	scanf("%d",&N);
	while (N--)
	{
		scanf("%d%d",&y,&s);
		while(1) 
		{  
            if (leap(y) == 1)
				break;  
            y++;  
        }  
		for(i=0;i<s-1;)
		{
			y+=4;
			if(y%4==0&&y%100!=0||y%400==0)
				i++;
		}
		printf("%d\n",y);
	}
	return 0;
}

