#include <stdio.h>
#include <string.h>
char a[100];
char d[]={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
void encryption();
void decryption();
void encryption()
{
  int a,b,i=0,j=0;
  char x[100],k[10],y[100];
  printf("Please input the message:");
  gets(x);

  printf("\n");

  printf("Please the key:");
  gets(k);

  printf("\n");

  a=strlen(x);
  b=strlen(k);

  if(a>b)
  {
   for(i=0;i<a;i++)

      {
       y[i]=(x[i]+k[j]-97-97)%26+97;
       printf("%c",y[i]);
       j++;
       if(j>=b)
       {j=0;}

      }
  }
else
     {for(i=0;i<a;i++)

      {
       y[i]=(x[i]+k[j]-97-97)%26+97;
       printf("%c",y[i]);
       j++;
      }
     }
printf("\n");
}
void decryption()
{
  int a,b,i=0,j=0;
  char x[100],k[10],y[100];
  printf("Please input the message:");
  gets(x);

  printf("\n");

  printf("Please the key:");
  gets(k);

  printf("\n");

  a=strlen(x);
  b=strlen(k);

  if(a>b)
  {
   for(i=0;i<a;i++)

      {
       y[i]=(x[i]-k[j]+26)%26+97;
       printf("%c",y[i]);
       j++;
       if(j>=b)
       {j=0;}

      }
  }
else
     {for(i=0;i<a;i++)

      {
       y[i]=(x[i]-k[j]+26)%26+97;
       printf("%c",y[i]);
       j++;
      }
     }
printf("\n");
}
int main()
 {int i;
 list:printf("please choose a function:1.encryption 2.decryption 3.exit\n");
 scanf("%d",&i);
 getchar();
 switch(i){
 case 1:encryption();
 goto list;
 case 2:decryption();
 goto list;
 //case 3:exit(1);
 }
 return 0;
}
///symmetric schemes require both partise to share a common secret key
