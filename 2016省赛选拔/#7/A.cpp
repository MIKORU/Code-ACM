#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#define LL long long
#define esp 1e-8
#define CAN(a,b) memset(a,b,sizeof(a))  //大数 memset(a,0x7f,sizeof(a));
const int INF = 0x3f3f3f3f;
int angle,rate;
int time,t,r;
double mins,second;
int h,m,s;
char op[10];
int T;
int cases =1;
int main()
{

    scanf("%d",&T);
    while(T--){
        scanf("%d%s%d",&angle,op,&time);
        t = 30*(12-time);
        rate = angle-t;
        if(op[0]=='a'){
            if(rate <= 0){
                rate+=360;
            }
            mins = rate/(5+0.5);
            while(mins >= 60){
                time++;
                mins -= 60;
            }
            if(time>12){
                time -= 12;
            }
            m = (int)mins;
        }
        else{
            if(rate >=0 ){
                rate -= 360;
            }
            mins = rate/(5+0.5);
            time--;
            while(mins <= -60){
                time--;
                mins += 60;
            }
            if(time<=0){
                time += 12;
            }
            if(fabs(mins)<=esp){
                time++;
                if(time>12)
                    time-=12;
            }
            else mins +=60;
            m = (int)mins;
        }
        h = time;
        second = (mins-(int)mins)*60;
        s = (int)(second+0.5);
        printf("Case %d: %d:%02d:%02d\n",cases++,h,m,s);
    }
    return 0;
}
