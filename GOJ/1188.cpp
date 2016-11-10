#include <stdio.h>
#include <math.h>
int main()
{
    double r,x,a,b;
    while (scanf ("%lf%lf",&a,&b)!=EOF){
        x=fabs(a*a-b*b)/2.0/(a+b);
        if (a>b){
            r=sqrt((a/2.0-x)*(a/2.0-x)+(a/2)*(a/2));
        }
        else {
            r=sqrt((b/2.0-x)*(b/2.0-x)+(b/2)*(b/2));
        }
        printf ("%.2f\n",3.1416*r*r);
    }
    return 0;
}
