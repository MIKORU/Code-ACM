//�����abcd=��ab+cd)^2 ���ʵ�4λ������дһ������������������������ʵ�4λ����
#include<stdio.h>
int main()
{int T,a,b,c,d;
	for(T=1000;T<10000;T++)
		{a=T/1000;
		 b=T/100%10;
		 c=T/10%10;
		 d=T%10;
			 if(T==(((a*10+b)+(c*10+d))*((a*10+b)+(c*10+d))))
				 printf("%d\n",T);
		}
	return 0;
}

//���򵥵ĽⷨTOT
/*
#include<stdio.h>
int main()
{int T,a,b;
	for(T=1000;T<10000;T++)
		{a=T/100;
		 b=T%100;
			 if(T==(a+b)*(a+b))
				 printf("%d\n",T);
		}
	return 0;
}
*/
