//POJ 1008
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char *Haab[] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char *Tzolkin[] = {"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
int days,month,years;
int sum;
char months[10];
int can(char a[],char b[])
{
    int lena = strlen(a);
    int lenb = strlen(b);
    if(lena==lenb)
    {
        for(int i=0;i<lena;i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
    return false;
}
int main()
{
    int T,t;
    scanf("%d",&T);
    printf("%d\n",T);
    while(T--)
    {
        int k = 0;
        scanf("%d. %s %d",&days,months,&years);
        for(int i=0;i<19;i++)
        {
            if(strcmp(months,Haab[i])==0){
                month = i;
            }
        }
        //1. uayet 0
        //printf("£¡£¡£¡£¡£¡£¡£¡dsbnaodnhosai\n");
//        if(month < 18){
//            sum = years*365+month*20+days+1;
//        }
        /*else */
        sum = years*365+month*20+days;
        //printf("sum = %d\n",sum);
        years = sum/260;
        sum = sum%260;
        k = sum%20;
        //printf("k = %d\n",k);
        sum = sum%13+1;
        printf("%d %s %d\n",sum,Tzolkin[k],years);
    }
    return 0;
}
