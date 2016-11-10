#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<iostream>
using namespace std;
#define RE(x) freopen(x,"r",stdin);
#define WR(x) freopen(x,"w",stdout);
#define N 100005
const int  MOD = 1000000007;
const int MAX_N = 99999999;
const int MAX_SIZE = 10;
#define LL long long
const int base=(int)log10(MAX_N+1.5);
///bits = MAX_SIZE * base
struct BigNum
{
    bool neg;
    int bit[MAX_SIZE];
    int len;
    BigNum(){BigNum(0);}
    BigNum(long long x)
    {
        clear();
        if(x<0){x=-x,neg=1;}
        for(int i=0;x!=0;i++)
        {
            bit[i]=x%(MAX_N+1);
            x/=(MAX_N+1);
            len=i;
        }
    }
    BigNum(int x){
        clear();
        if(x<0){x=-x,neg=1;}
        for(int i=0;x!=0;i++)
        {
            bit[i]=x%(MAX_N+1);
            x/=(MAX_N+1);
            len=i;
        }
    }
    BigNum& operator = (long long x){*this = BigNum(x);return *this;}
    BigNum operator = (int x){*this = BigNum(x);return *this;}
    BigNum(const char a[])
    {
        clear();
        int l=strlen(a),index=0,ten=1;
        if(a[0]=='-') neg=1;
        for(int i=l-1,j=1;i>=neg;i--,j++)
        {
            bit[index]+=(a[i]-'0')*ten;
            ten*=10;
            if((j)%base==0) {index++;ten=1;}
        }
        for(int i=index+1;i>=0;i--)if(bit[i]!=0){len=i;break;}
    }
    BigNum(string a)
    {
        clear();
        int l=a.length(),index=0,ten=1;
        if(a[0]=='-') neg=1;
        for(int i=l-1,j=1;i>=neg;i--,j++)
        {
            bit[index]+=(a[i]-'0')*ten;
            ten*=10;
            if((j)%base==0) {index++;ten=1;}
        }
        for(int i=index+1;i>=0;i--)if(bit[i]!=0){len=i;break;}
    }
    void print()
    {
        if(neg) putchar('-');
        bool ok=1,pre=1;
        for(int i=len;i>=0;i--)
        {
            if(ok&&bit[i]==0) continue;
            else{
                if(pre){
                    printf("%d",bit[i]);
                    pre=ok=0;
                }else{
                    printf("%0*d",base,bit[i]);
                }
            }
        }
        if(ok) printf("0");
        //printf("\n");
    }
    void clear()
    {
        for(int i=0;i<MAX_SIZE;i++)
            bit[i]=0;
        len=0;
        neg=false;
    }
    friend istream& operator>>(istream&,  BigNum&);   //重载输入运算符
	friend ostream& operator<<(ostream&,  BigNum&);   //重载输出运算符
};
istream & operator>>(istream &is,BigNum& b)
{
    b.clear();
    char a[MAX_SIZE*base];
    is >> a;
    int l=strlen(a),index=0,ten=1;
    if(a[0]=='-'){
        b.neg=1;
    }
    for(int i=l-1,j=1;i>=b.neg;i--,j++)
    {
        b.bit[index]+=(a[i]-'0')*ten;
        ten*=10;
        if((j)%base==0) {index++;ten=1;}
    }
    for(int i=index+1;i>=0;i--)
        if(b.bit[i]!=0)
        {
            b.len=i;break;
        }
    return is;
}
ostream& operator<<(ostream& out,  BigNum& b)
{
    if(b.neg) cout<<'-';
    int i;
	cout << b.bit[b.len];
	for(i = b.len - 1 ; i >= 0 ; i--)
	{
		cout.width(base);
		cout.fill('0');
		cout << b.bit[i];
	}
	return out;
}
BigNum operator *(BigNum a,long long x);
BigNum operator - (BigNum a,BigNum b);
bool operator < (BigNum a,BigNum b)
{
    if(a.neg!=b.neg) return a.neg>b.neg;
    if(a.neg==b.neg&&a.neg==1) return b*(-1)<a*(-1);
    if(a.len<b.len) return true;
    else if(a.len==b.len)
    for(int i=a.len;i>=0;i--)
    {
        if(a.bit[i]==b.bit[i]) continue;
        if(a.bit[i]<b.bit[i]) return true;
        else return false;
    }
    return false;
}
bool operator < (BigNum a,long long b){return a<BigNum(b);}
bool operator > (BigNum a,BigNum b)
{
    if(a.neg!=b.neg) return a.neg<b.neg;
    if(a.neg==b.neg&&a.neg==1) return b*(-1)>a*(-1);
    if(a.len>b.len) return true;
    else if(a.len==b.len)
    for(int i=a.len;i>=0;i--)
    {
        if(a.bit[i]==b.bit[i]) continue;
        if(a.bit[i]>b.bit[i]) return true;
        else return false;
    }
    return false;
}
bool operator > (BigNum a,long long b){return a>BigNum(b);}
bool operator <= (BigNum a,BigNum b){return !(a>b);}
bool operator <= (BigNum a,long long b){return !(a>BigNum(b));}
bool operator >= (BigNum a,BigNum b){return !(a<b);}
bool operator >= (BigNum a,long long b){return !(a<BigNum(b));}
bool operator == (BigNum a,BigNum b){return (a>=b&&b>=a);}
bool operator == (BigNum a,long long x){return a==BigNum(x);}
BigNum operator + (BigNum a,BigNum b)
{
    if(a.neg&&!b.neg) return b-a*(-1);
    if((!a.neg)&&b.neg) return a-b*(-1);
    int i,l=max(a.len,b.len);
    BigNum sum;
    sum.clear();
    int t=0;
    for(i=0;i<=l+1;i++)
    {
        sum.bit[i]=a.bit[i]+b.bit[i]+t/(MAX_N+1);
        t=a.bit[i]+b.bit[i];
        sum.bit[i]%=MAX_N+1;
    }
    if(sum.bit[l+1]!=0) sum.len=l+1;
    else sum.len=l;
    sum.neg=a.neg;
    return sum;
}
BigNum operator - (BigNum a,BigNum b)
{
    if(a.neg&&!b.neg) return (b+a*(-1))*(-1);
    if((!a.neg)&&b.neg) return a+b*(-1);
    if(a.neg&&b.neg) return (b*(-1)-a*(-1));
    if(a==b) return BigNum(0);
    if(a<b) return (b-a)*(-1);
    BigNum ans=0;
    for(int i=0;i<=a.len;i++)
    {
        ans.bit[i]=a.bit[i]-b.bit[i];
        if(ans.bit[i]<0){
            ans.bit[i]+=MAX_N+1;
            for(int j=i+1;j<=a.len;j++)
            {
                if(a.bit[j]>0){
                    a.bit[j]--;break;
                }
                else a.bit[j]+=MAX_N;
            }
        }
    }
    for(int i=a.len;i>=0;i--)
    if(ans.bit[i]>0){ans.len=i;break;}
    return ans;
}
BigNum operator * (BigNum a,BigNum b)
{
    BigNum sum;
    sum.clear();
    if(a==BigNum(0)||b==BigNum(0)) return BigNum(0);
    LL t,s;
    for(int i=0;i<=a.len;i++)
    {
        t=s=0;
        for(int j=0;j<=b.len;j++)
        {
            t=(LL)a.bit[i]*(LL)b.bit[j];
            sum.bit[i+j]+=(int)(t%(LL)(MAX_N+1));
            sum.bit[i+j+1]+=(int)((t)/(LL)(MAX_N+1))+sum.bit[i+j]/(MAX_N+1);
            sum.bit[i+j]%=MAX_N+1;
        }
    }
    for(int i=a.len+b.len+2;i>=0;i--)
    {
        if(sum.bit[i]!=0){
            sum.len=i;break;
        }
    }
    sum.neg=a.neg^b.neg;
    return sum;
}
BigNum operator * (BigNum a,long long x){return BigNum(x)*a;}

BigNum operator ^(BigNum a,int b)
{
    BigNum r,base=a;
    r.clear();
    r.bit[0]=1;
    while(b)
    {
        if(b&1)
            r=r*base;
        base=base*base;
        b>>=1;
    }
    return r;
}

void toString(BigNum s,char a[])
{
    memset(a,0,sizeof(a));
    bool ok=1,pre=1;
    char t[20];
    for(int i=s.len;i>=0;i--)
    {
       if(ok&&s.bit[i]==0) continue;
        else{
            if(pre){
                sprintf(t,"%d",s.bit[i]);
                strcat(a,t);
                pre=ok=0;
            }else{
                sprintf(t,"%0*d",base,s.bit[i]);
                strcat(a,t);
            }
        }
    }
    if(ok) sprintf(a,"0");
}
BigNum operator /(BigNum a,int n)
{
    BigNum ans;
    bool neg=0;
    if(n<0){n=-n;neg=1;}
    ans.clear();
    long long t=0;
    for(int i=a.len;i>=0;i--)
    {
        t=(long long)a.bit[i]+t*(MAX_N+1);
        ans.bit[i]=t/n;
        t=t%n;
    }
    for(int i=a.len;i>=0;i--)if(ans.bit[i]!=0)
    {
        ans.len=i;break;
    }
    ans.neg=a.neg^neg;
    return ans;
}
int operator %(BigNum a,int n)
{
    long long t=0;
    for(int i=a.len;i>=0;i--)
    {
        t=(long long)a.bit[i]+t*(MAX_N+1);
        t=t%n;
    }
    return t;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        long long a, b, c, d;
        scanf("%lld", &a);
        b = a/2, a = a/2 + (a&1);
        if(a&1) c=a, d=a/2;
        else c=a-1, d=a/2;
        if(b&1) a=b, b=b/2;
        else a=b-1, b=b/2;
        ((BigNum(a)*BigNum(b))+(BigNum(c)*BigNum(d))).print();
        printf("\n");
    }
    return 0;
}
