#include<iostream>
#include<stdio.h>
#include<cstring>
#include<fstream>

using namespace std;


typedef struct HashNode
{
	char *word;
	int count;
	struct HashNode* next;
}tHashNode;

const int NHASH = 127;
const int MULT = 31;
struct HashNode* bin[NHASH];


unsigned int hash(char *p)
{
	unsigned int h = 0;
	for(;*p;p++)
	{
		h = MULT * h + (*p);
	}
	return h % NHASH;
}

void incword(char *s)
{
	int pos = hash(s);
	tHashNode *p;
	for(p = bin[pos];p!=NULL;p=p->next)
	{
		if( strcmp(s,p->word)==0 )
		{
			(p->count)++;
			return ;
		}
	}


	p = new tHashNode();
	p->word = new char[strlen(s)+1];
	strcpy(p->word,s);
	p->count = 1;

	p->next = bin[pos];
	bin[pos] = p;
}

int main()
{


	for(int i=0;i<NHASH;i++)
	{
		bin[i] = NULL;
	}

	char buf[100];

	while(cin>>buf)
	{
		incword(buf);
	}

	tHashNode *p;
	int j = 0;
	for(int i=0;i<NHASH;i++)
	{
		cout<<"Bucket "<<i<<" : ";
		for( p = bin[i];p!=NULL;p=p->next)
		{
			cout<<"| "<<p->word<<" "<<p->count<<" |";
			j++;
		}
		cout<<endl;
	}

    cout<<"Number of Words : "<<j<<endl;
    return 0;
}
