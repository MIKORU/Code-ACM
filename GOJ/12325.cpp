#include<stdio.h>
#include<math.h>
int  prime(int  x)
{int  i;
for(i=2;i<=sqrt(x);i++)
   {if(x%i==0)
    return 0;
   }
    return 1;
}

void main()
{int i,j,flag,n;
 for(i=1;i<=5000;i++)
    if(prime(i)==1)
     {flag=0;
      n=i;
      while(n!=0)
      {j=n/10;
       n=n%10;
       if(prime(j)==0||prime(i)==0)
            {flag=1;break;}

      }
      if(flag==0)
        printf("%d\n",i);

     }
}

