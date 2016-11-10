#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 26;
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
			q = (Trie *)malloc(sizeof(root));
			q->v = 0;
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
    if(p->v == 0 )
        puts("OH GOD");
    else
        printf("%s%d\n",str,p->v);
}
char word[120];
int main(){
	int n;
	for(int i=0;i<MAXN;i++){
		root.next[i] = NULL;
	}
	while(~scanf("%d",&n)){
        getchar();
		for(int i=0;i<n;i++){
			gets(word);
			createTrie(word);
		}
	}
	return 0;
}
