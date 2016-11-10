#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MAXSIZE 100

typedef int Status;
typedef int ElemType;


typedef struct SqList{
    ElemType *elem;
    int length;
}SqList;
/**
*��ʼ��
**/
Status initList(SqList &L,int len){
    L.elem = new ElemType[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length = len;
    for(int i=0;i<L.length;i++){
        scanf("%d",&L.elem[i]);
    }
    return OK;
}
/**
*�Ƿ�ǿ�
*/
Status is_empty_Sq(SqList &L){
    if(L.length == 0)
        return OK;
    else return ERROR;
}
/**
*��ʾ
**/
void print_Sq(SqList &L){
    if(is_empty_Sq(L))
        printf("���\n");
    else{
        for(int i=0;i<L.length;i++)
            printf("%d ",*(L.elem+i));
        putchar('\n');
    }
    getchar();
}
/**
*����
**/
int LocateELem_Sq(SqList L,ElemType e){
    for(int i=0;i<L.length;i++)
        if(L.elem[i] == e)
            printf("��Ҫ���ҵ�ֵλ�ڵ�%dλ\n",i+1);
    return 0;
}
/**
*������ֵ
*/
void sort_LocateELem_Sq(SqList L){
    for(int i=0;i<L.length;i++)
        for(int j=i+1;j<L.length;j++){
            if(L.elem[i]<L.elem[j]){
                int k;
                k = L.elem[i];
                L.elem[i] = L.elem[j];
                L.elem[j] = k;
            }
        }
    printf("���ֵΪ��%d\n",L.elem[0]);
}
/**
*����
**/
Status ListInsert_Sq(SqList &L,int i,ElemType e){
    if(i <1 || i>L.length +1){
        printf("����λ�ò���ȷ\n");
    return ERROR;
    }
    if(L.length == MAXSIZE){
            printf("overflow!\n");
    return ERROR;
    }
    for(int j = L.length -1;j>=i-1;j--)
        L.elem[j+1] = L.elem[j];
    L.elem[i-1] = e;
    ++L.length;
    return OK;
}
/**
*����
*/
void ListRever_Sq(SqList &L){
    int left = 0,right = L.length-1;
    int buf,counts = L.length/2;
    for(int j = 0;j<counts;j++){
        buf = L.elem[left];
        L.elem[left++] = L.elem[right];
        L.elem[right--] = buf;
    }
    print_Sq(L);
}
/**
*ɾ��
*/
Status ListDelete_Sq(SqList &L,int i,ElemType &e){
    if((i<1)||(i>L.length)){
        printf("the position %d is wrong!\n",i);
    return 0;
    }
    e = L.elem[i-1];
    for(int j=i;j<=L.length-1;j++)
        L.elem[j-1] = L.elem[j];
    --L.length;
    return OK;
}
/**
*ƽ��ֵ
*/
Status ListAve_Sq(SqList &L){
    float sum = 0;
    if(L.length == 0)
        return ERROR;
    for(int j=0;j<L.length;j++){
        sum += L.elem[j];
    }
    printf("ƽ��ֵΪ��%f\n",sum/L.length);
    return OK;
}
/**
*��� ����
*/
Status ListClear_Sq(SqList &L){
    L.length = 0;
    return OK;
}
/**
*����
*/
Status ListDestroy_Sq(SqList &L){
    if(L.elem)
        free(L.elem);
    return OK;
}
//�������ݣ�21 18 30 75 42 55 99 35 40
int main(){
    int n,length;
    SqList sq1;
    ElemType e;
    initList(sq1,9);
//    print_Sq(sq1);
//    ListInsert_Sq(sq1,3,67);
//    ListInsert_Sq(sq1,9,10);
//    print_Sq(sq1);
//    LocateELem_Sq(sq1,10);
//    sort_LocateELem_Sq(sq1);
//    ListRever_Sq(sq1);
//    if(ListDelete_Sq(sq1,4,e)&&ListDelete_Sq(sq1,7,e))
//        printf("ɾ���ɹ�\n");
//    print_Sq(sq1);
//    ListAve_Sq(sq1);
    ListClear_Sq(sq1);
    ListDestroy_Sq(sq1);
    return 0;
}


