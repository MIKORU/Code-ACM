//������
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MAXSIZE 100
using namespace std;

typedef int Status;
typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
Status InitList_L(LinkList &L){  ///��ʼ��
    L = new LNode;
    L->next = NULL;
    return OK;
}
Status GetElem_L(LinkList L,int i,ElemType &e){ ///�õ�ĳ������Ԫ��
    LinkList p;
    p = L->next;
    int j = 1;
    while(p&&j<i){
        p = p->next;
        ++j;
    }
    if(!p||j>i)
        return ERROR;
    e = p->data;
    return OK;
}
LNode *LocateElem_L(LinkList L,ElemType e){ ///Ԫ��ֵ����
    LNode *p;
    p = L->next;
    while(p&&p->data!=e)
        p = p->next;
    return p;
}
Status ListInsert_L(LinkList &L,int i,ElemType e){ ///����
    LinkList p;
    p=L;
    int j=0;
    while(p&&j<i-1){
        p = p->next;
        ++j;
    }
    if(!p||j>i-1)
        return ERROR;
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
Status ListDelete_L(LinkList &L,int i,ElemType &e){ ///ɾ��
    LinkList p;
    p=L;
    int j=0;
    while(p->next&&j<i-1){
        p = p->next;
        ++j;
    }
    if(!(p->next)||j>i-1)
        return ERROR;
    LNode *q;
    q = p->next;
    p->next = q->next;
    e = q->data;
    delete q;
    return OK;
}
void CreateList_F(LinkList &L,int n){  ///ǰ��
    L = new LNode;
    L->next = NULL;
    for(int i=n;i>0;i--){
        LNode *p = new LNode;
        cin>>p->data;
        p->next = L->next;
        L->next = p;
    }
}
void CreateList_L(LinkList &L,int n){  ///���
    L = new LNode;
    L->next = NULL;
    LinkList r;
    r = L;
    for(int i=0;i<n;i++){
        LNode *p = new LNode;
        cin>>p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}
void print_List(LinkList &L){
    LinkList p = L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
Status ListLength(LinkList &L){
    LinkList p = L;
    int i=0;
    while(p->next){
        ++i;
        p = p->next;
    }
    return (i);
}
void print_sortList(LinkList &L){
    LinkList p = L->next;
    int s = ListLength(L)-1;
    printf("��СֵΪ��%d\n",p->data);
    while(s--){
        p = p->next;
    }
    printf("���ֵΪ��%d\n",p->data);
    printf("\n");
}
Status DestroyList(LinkList &L){
    LinkList p;
    LNode *q = L->next;
    while(q){
        p = q->next;
        free(q);
        q = p;
    }
    L->next = NULL;
    return OK;
}
Status Reverse_List(LinkList &L){
    LinkList p,s;
    p=s=L->next;
    L->next=NULL;
    while(p)
    {
        s=s->next;
        p->next=L->next;
        L->next=p;
        p=s;
    }
    return OK;
}
Status Sort_List(LinkList &L)
{
    LinkList newhead, s, pre , p;
    p=L->next;
    newhead=p->next;
    p->next=NULL;
    while(newhead){
        s=newhead;
        newhead=newhead->next;
        pre=L;
        p=L->next;
        while(p!=NULL && p->data < s->data)
        {
            pre=p;
            p=p->next;
        }
        s->next=p;
        pre->next=s;
    }
    return OK;
}

int main(){
    LinkList sq;
    ElemType e;
    CreateList_F(sq,9);
    print_List(sq);
//    printf("�õ�����ĳ���Ϊ��%d\n",ListLength(sq));
//    printf("��������Ҫ���ҵ�ֵ��");
//    int n;
//    cin>>n;
//    printf("�����ҵ�ֵ��%dλ\n",*LocateElem_L(sq,n));
//    printf("��������Ҫ�����λ�ú���ֵ��");
//    int x,y;
//    cin>>x>>y;
//    ListInsert_L(sq,x,y);
//    print_List(sq);
//    printf("��������Ҫɾ����λ�ã�");
//    cin>>x;
//    ListDelete_L(sq,x,e);
//    print_List(sq);
//    Reverse_List(sq);
//    print_List(sq);
    Sort_List(sq);
    print_List(sq);
    print_sortList(sq);
//    DestroyList(sq);
//    print_List(sq);
    return 0;
}
