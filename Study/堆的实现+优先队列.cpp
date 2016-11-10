#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <queue>  //priority_queue<int>
#include <utility> //pair类或者 typedef pair<int ,int>P;
#define LL long long
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a))
#define MAX_N 10005
const int INF = 0x3f3f3f3f;
using namespace std;

/**堆的性质，儿子的值一定不小于父亲的二叉树
int heap[MAX_N],sz = 0;
void push(int x)
{
    int i = sz++;
    while(i>0)
    {
        //父亲节点的编号p
        int p = (i-1)/2;
        if(heap[p]<=x)
            break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = x;
}
int pop()
{
    int ret = heap[0];
    int x = heap[--sz];
    int i = 0;
    while(i*2+1<sz)
    {
        int a = i*2+1,b = i*2+2;
        if(b<sz&&heap[b]<heap[a])
            a=b;
        if(heap[a]>=x)
            break;
        heap[i] = heap[a];
        i=a;
    }
    heap[i] = x;
    return ret;
}
**/
//优先队列STL实现，取到的是最大值。
//以下有拓展延伸
struct cmp1{
    bool operator ()(int &a,int &b){
        return a>b;//最小值优先
    }
};
struct cmp2{
    bool operator ()(int &a,int &b){
        return a<b;//最大值优先
    }
};
struct number1{
    int x;
    bool operator < (const number1 &a) const {
        return x>a.x;//最小值优先
    }
};
struct number2{
    int x;
    bool operator < (const number2 &a) const {
        return x<a.x;//最大值优先
    }
};
int a[]={14,10,56,7,83,22,36,91,3,47,72,0};
number1 num1[]={14,10,56,7,83,22,36,91,3,47,72,0};
number2 num2[]={14,10,56,7,83,22,36,91,3,47,72,0};

int main()
{   priority_queue<int>que;//采用默认优先级构造队列

    priority_queue<int,vector<int>,cmp1>que1;//最小值优先
    priority_queue<int,vector<int>,cmp2>que2;//最大值优先

    priority_queue<int,vector<int>,greater<int> >que3;//注意“>>”会被认为错误，
                                                      //这是右移运算符，所以这里用空格号隔开
    priority_queue<int,vector<int>,less<int> >que4;////最大值优先

    priority_queue<number1>que5;
    priority_queue<number2>que6;

    int i;
    for(i=0;a[i];i++){
        que.push(a[i]);
        que1.push(a[i]);
        que2.push(a[i]);
        que3.push(a[i]);
        que4.push(a[i]);
    }
    for(i=0;num1[i].x;i++)
        que5.push(num1[i]);
    for(i=0;num2[i].x;i++)
        que6.push(num2[i]);


    printf("采用默认优先关系:\n(priority_queue<int>que;)\n");
    printf("Queue 0:\n");
    while(!que.empty()){
        printf("%3d",que.top());
        que.pop();
    }
    puts("");
    puts("");

    printf("采用结构体自定义优先级方式一:\n(priority_queue<int,vector<int>,cmp>que;)\n");
    printf("Queue 1:\n");
    while(!que1.empty()){
        printf("%3d",que1.top());
        que1.pop();
    }
    puts("");
    printf("Queue 2:\n");
    while(!que2.empty()){
        printf("%3d",que2.top());
        que2.pop();
    }
    puts("");
    puts("");
    printf("采用头文件\"functional\"内定义优先级:\n(priority_queue<int,vector<int>,greater<int>/less<int> >que;)\n");
    printf("Queue 3:\n");
    while(!que3.empty()){
        printf("%3d",que3.top());
        que3.pop();
    }
    puts("");
    printf("Queue 4:\n");
    while(!que4.empty()){
        printf("%3d",que4.top());
        que4.pop();
    }
    puts("");
    puts("");
    printf("采用结构体自定义优先级方式二:\n(priority_queue<number>que)\n");
    printf("Queue 5:\n");
    while(!que5.empty()){
        printf("%3d",que5.top());
        que5.pop();
    }
    puts("");
    printf("Queue 6:\n");
    while(!que6.empty()){
        printf("%3d",que6.top());
        que6.pop();
    }
    puts("");
    return 0;
}
