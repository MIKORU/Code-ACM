
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 26;
typedef struct Trie
{
	Trie *next[MAXN];
	int v;  //һ���ֵ��������ж�����ͬǰ׺����Ŀ
}Trie;
Trie root;
void createTrie(char *str){
	int len = strlen(str);
	Trie *p = &root,*q;
	for(int i=0;i<len;i++){
		int id = str[i] -'a';
		if(p->next[id] == NULL){   //��Ϊ�� �������q
			q = (Trie *)malloc(sizeof(root));
			q->v = 1;
			for(int j=0;j<MAXN;j++)
				q->next[j] = NULL;
			p->next[id] = q;  //p��q����ָ
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
		if(p==NULL)  //�������Դ�Ϊǰ׺���ַ���
			return 0;
	}
	return p->v;
}
//�ͷ��ڴ�
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
	char str[15];
	for(int i=0;i<MAXN;i++)
		root.next[i] = NULL;
	while(gets(str)&&str[0]!='\0')
		createTrie(str);
    memset(str,0,sizeof(str));
	while(~scanf("%s",&str)){
		int ans = findTrie(str);
		printf("%d\n",ans);

	}
	return 0;
}
