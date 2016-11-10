#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    long long  a,b,i,sum;
    while(cin>>a>>b)
    {
        sum=0;
        if(a==b)
            cout<<"SB"<<endl;
        if(a<b)
            cout<<"0"<<endl;
        if(a>b)
            {
                for(i=1;i*i<a-b;i++)
                    {
                        if((a-b)%i==0){
                            sum+=(i>b);
                            sum+=((a-b)/i>b);
                        }
                    }
                    if(i*i==a-b){
                        sum+=(i>b);
                    }
               cout<<sum<<endl;
            }
    }
return 0;
}
