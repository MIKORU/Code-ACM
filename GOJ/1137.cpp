#include <stdio.h>
int main()
{
	char a[5];
	while(scanf("%s",&a)!=EOF)
	{
		switch(a[0])
		{
		case 'A':printf("Accepted!\n");break;
		case 'W':printf("Wrong Answer!\n");break;
		case 'P':printf("Presentation Error!\n");break;
		case 'C':printf("Compilation Error\n");break;
		case 'T':printf("Time Limit Exceeded!\n");break;
		case 'R':printf("Runtime Error!\n");break;
		default:break;
		}
	}
	return 0;
}