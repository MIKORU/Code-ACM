#include<cstdio>

#define MAXSIZE 100

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;
typedef int SElemType;

typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack &S){
    S.base = new SElemType;
    if(!S.base)
            return OVERFLOW;
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
Status Push(SqStack &S,SElemType e){
    if(S.top - S.base == S.stacksize)
        return ERROR;
    *S.top++ = e;
    return OK;
}
Status Pop(SqStack &S,SElemType &e){
    if(S.top == S.base)
        return ERROR;
    e = *--S.top;
    return OK;
}
SElemType GetTop(SqStack S){
    if(S.top == S.base)
        return OK;
    return *(S.top-1);
}
int Stacklength(SqStack S){
    int length = S.top - S.base;
    return length;
}
Status DeleteStack(SqStack &S,int i,SElemType &e){
    SElemType *p;
    for(p = S.base;p!=S.top-1;p++){
        if(*p == i){
            e = *p;
            p = p-1;
            break;
        }
    }
    while(p!=S.top-1){
        p++;
        *p = *(p+1);
    }
    --S.top;
    return OK;
}
Status ReverStack(SqStack S){
    SElemType a[MAXSIZE];
    SElemType e;
    int length = Stacklength(S);
    for(int i=0;i<length;i++)
        Pop(S,a[i]);
    for(int i=0;i<length;i++)
        Push(S,a[i]);
    printf("逆置后栈内元素分别为:\n");
    while(length--){
        printf("%d ",GetTop(S));
        Pop(S,e);
    }
    printf("\n");
    return OK;
}
void show_stack(SqStack S){
    printf("栈内元素分别为:\n");
    SElemType e;
    int n = Stacklength(S);
    while(n--){
        printf("%d ",GetTop(S));
        Pop(S,e);
    }
    printf("\n");
}
int main(){
    SqStack sq1;
    InitStack(sq1);
    int n;
    SElemType a,e;
    printf("请输入进栈元素数量和值：");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        Push(sq1,a);
    }
    Pop(sq1,e);
    printf("元素出栈\n");
    printf("栈长度为：%d\n",Stacklength(sq1));
    printf("栈顶元素为：%d\n",GetTop(sq1));
    printf("请输入你想要删除的值:");
    scanf("%d",&a);
    DeleteStack(sq1,a,e);
    show_stack(sq1);
    printf("此时栈长度为：%d\n",Stacklength(sq1));
    ReverStack(sq1);
    printf("逆置后栈长度为：%d\n",Stacklength(sq1));
    return 0;
}
