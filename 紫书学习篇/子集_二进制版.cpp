#include <cstdio>
using namespace std;
void print_subset(int n,int s){
     for(int i=0;i<n;i++)
             if(s&(1<<i)) printf("%d ",i);
     printf("\n");
}
int main(){
    int a[]={1,2,5};
    for(int i=0;i<(1<<3);i++)
            print_subset(a[i],i);
}
