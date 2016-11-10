#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 26;
char a[20];
typedef struct Trie
{
    Trie *next[MAXN];
    int v;  //一个字典树到此有多少相同前缀的数目
}Trie;
Trie root;
void createTrie(char *str){
    int len = strlen(str);
    Trie *p = &root,*q;
    for(int i=0;i<len;i++){
        int id = str[i] -'a';
        if(p->next[id] == NULL){   //若为空 建立结点q
            q = (Trie *)malloc(sizeof(Trie));//建立空指针
            q->v = 1;
            for(int j=0;j<MAXN;j++)
                q->next[j] = NULL;
            p->next[id] = q;  //p，q互相指
            p = p->next[id];
        }
        else{
            p->next[id]->v++;
            p= p->next[id];
        }
    }
}
int findTrie(char *str){
    int len = strlen(str);
    Trie *p = &root;
    for(int i=0;i<len;i++){
        int id = str[i]-'a';
        p = p->next[id];
        if(p==NULL)  //不存在以此为前缀的字符串
            return 0;
    }
    return p->v;
}
//释放内存
int dealTrie(Trie *T){
    int i;
    if(T == NULL){
        return 0;
    }
    for(i=0;i<MAXN;i++){
        if(T->next[i]!=NULL)
            dealTrie(T->next[i]);
    }
    free(T);
    return 0;
}
int main(){
    int n,m;
    for(int i=0;i<MAXN;i++)
		root.next[i] = NULL;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%s",a);
            createTrie(a);
            memset(a,0,sizeof(a));
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%s",a);
            printf("%d\n",findTrie(a));
        }
    }
    return 0;
}
