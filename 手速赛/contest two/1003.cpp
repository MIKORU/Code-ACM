#include<iostream>
#include<cstdio>
using namespace std;

const int MaxN=2000;
const long long ModNum=100000007;

long long P[MaxN+1][MaxN+1],R[MaxN+1],Pow[MaxN+1],Ans;
int Loo,Loop,N,K;

long long ModExp(long long Base,long long T)
{
	if(T==0)
		return 1;
	long long Res=ModExp(Base,T>>1);
	Res=(Res*Res)%ModNum;
	if((T&1)==1)
		Res=(Res*Base)%ModNum;
	return Res;
}

void First()
{
	for(int i=1;i<=MaxN;i++)
		Pow[i]=ModExp(i,ModNum-2);
}

void Init()
{
	scanf("%d%d",&N,&K);
	K=min(K,N);
}

void Work()
{
	int i,j;
	P[1][0]=1;
	for(i=1;i<N;i++)
	{
		P[i+1][0]=0;
		for(j=0;j<=K;j++)
		{
			P[i+1][0]=(P[i+1][0]+P[i][j])%ModNum;
			P[i+1][j+1]=P[i][j];
		}
	}
	for(i=1;i<=N;i++)
		for(j=0;j<=K;j++)
			P[i][j]=(P[i][j]*(j+1))%ModNum;
	for(i=1;i<=N;i++)
	{
		R[i]=0;
		for(j=0;j<=K;j++)
			R[i]=(R[i]+P[i][j])%ModNum;
	}
	if(K>=N)
		Ans=1;
	else
		Ans=0;
	for(i=1;i<=N;i++)
		if((N%i)==0)
		{
			for(j=2*i;j<=N;j+=i)
				R[j]=(R[j]-R[i]+ModNum)%ModNum;
			Ans=(Ans+R[i]*Pow[i])%ModNum;
		}
}

void Print()
{
	printf("%lld\n",Ans);
}

int main()
{
	First();
	scanf("%d",&Loop);
	for(Loo=1;Loo<=Loop;Loo++)
	{
		Init();
		Work();
		Print();
	}
	return 0;
}
