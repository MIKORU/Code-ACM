
#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 10000000;
struct node{
    int left,right,mid;
    int cover;
    int f;
};
node seg_tree[3*MAXN];
void make(int l,int r,int num){ ///若它在数组中编号为num，则其左右子节点的编号为 2 * num，2 * num + 1
    seg_tree[num].left =l;
    seg_tree[num].right = r;
    seg_tree[num].mid = (l+r)/2;
    if(l+1!=r){  ///若不为叶子节点 则递归构造左右子树
        make(l,seg_tree[num].mid,2*num);
        make(seg_tree[num].mid,r,2*num+1);
    }
}
///各种操作
void insert(int l,int r,int num){
    if(seg_tree[num].left==l&&seg_tree[num].right==r){
        seg_tree[num].cover=l;
        return ;
    }
    if(r<=seg_tree[num].mid)
        insert(l,r,2*num);
    else if(l>=seg_tree[num].mid)
        insert(l,r,2*num+1);
    else{
        insert(l,seg_tree[num].mid,2*num);
        insert(seg_tree[num].mid,r,2*num+1);
    }
}
bool del(int l,int r,int num){
    if(seg_tree[num].left+1==seg_tree[num].right){
        int f = seg_tree[num].f;
        seg_tree[num].f =0;
        return f;
    }
    if(seg_tree[num].f==1){
        seg_tree[num].f=0;
        seg_tree[2*num].f=1;
        seg_tree[2*num+1].f=1;
    }
    if(r<=seg_tree[num].mid)
        return del(l,r,2*num);
    else if(l>=seg_tree[num].mid)
        return del(l,r,2*num+1);
    else
        return del(l,seg_tree[num].mid,2*num)&&del(seg_tree[num].mid,r,2*num+1);
}
int main()
{

}
