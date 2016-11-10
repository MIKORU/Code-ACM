#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10001
#define LEN 31
int next[N*LEN][130];
int cnt[N*LEN];
int node;

char tree[N][LEN],s[LEN];
int species,all;

int cmp(const void *a,const void *b)
{
    return strcmp((char *)a,(char *)b);
}
void init()
{
    species=all=0;
    node=1;
    memset(next[0],0,sizeof(next[0]));
}
void add(int cur,int k)
{
    memset(next[node],0,sizeof(next[node]));
    cnt[node]=0;
    next[cur][k]=node++;
}
void insert(char s[])
{
    int i,k,cur;
    all++;
    for(i=cur=0;s[i];i++)
    {
        k=s[i];
        if(!next[cur][k])   add(cur,k);
        cur=next[cur][k];
    }
    if(!cnt[cur])   strcpy(tree[species++],s);
    cnt[cur]++;
}
int query(char s[])
{
    int i,k,cur;
    for(i=cur=0;s[i];i++)
    {
        k=s[i];
        cur=next[cur][k];
    }
    return cnt[cur];
}
int main()
{
    init();
    while(gets(s))
        if(s[0])
        insert(s);
    qsort(tree,species,sizeof(tree[0]),cmp);
    for(int i=0;i<species;i++)  printf("%s %.4lf\n",tree[i],query(tree[i]));
    return 0;
}
