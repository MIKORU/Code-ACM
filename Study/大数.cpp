//#include<cstdio>
//#include<cstring>
//#include<vector>
//#include<iostream>
//using namespace std;
//
//struct BigInteger {
//  static const int BASE = 100000000;
//  static const int WIDTH = 8;
//  vector<int> s;
//
//  BigInteger(long long num = 0) { *this = num; } // 构造函数
//  BigInteger operator = (long long num) { // 赋值运算符
//    s.clear();
//    do {
//      s.push_back(num % BASE);
//      num /= BASE;
//    } while(num > 0);
//    return *this;
//  }
//  BigInteger operator = (const string& str) { // 赋值运算符
//    s.clear();
//    int x, len = (str.length() - 1) / WIDTH + 1;
//    for(int i = 0; i < len; i++) {
//      int end = str.length() - i*WIDTH;
//      int start = max(0, end - WIDTH);
//      sscanf(str.substr(start, end-start).c_str(), "%d", &x);
//      s.push_back(x);
//    }
//    return *this;
//  }
//  BigInteger operator + (const BigInteger& b) const {
//    BigInteger c;
//    c.s.clear();
//    for(int i = 0, g = 0; ; i++) {
//      if(g == 0 && i >= s.size() && i >= b.s.size()) break;
//      int x = g;
//      if(i < s.size()) x += s[i];
//      if(i < b.s.size()) x += b.s[i];
//      c.s.push_back(x % BASE);
//      g = x / BASE;
//    }
//    return c;
//  }
//  BigInteger operator += (const BigInteger &b)
//  {
//      *this = *this +b;
//      return *this;
//  }
//
//
//};
//
//ostream& operator << (ostream &out, const BigInteger& x) {
//  out << x.s.back();
//  for(int i = x.s.size()-2; i >= 0; i--) {
//    char buf[20];
//    sprintf(buf, "%08d", x.s[i]);
//    for(int j = 0; j < strlen(buf); j++) out << buf[j];
//  }
//  return out;
//}
//
//istream& operator >> (istream &in, BigInteger& x) {
//  string s;
//  if(!(in >> s)) return in;
//  x = s;
//  return in;
//}
//
//
//
//#include<set>
//#include<map>
//set<BigInteger> s;
//map<BigInteger, int> m;
//
//int main() {
//  BigInteger a[1005];
//  int n;
//  a[0] = 0;
//  a[1] = 1;
//  for(int i=2;i<102;i++)
//    a[i] = a[i-1]+a[i-2];
//  while(cin>>n)
//  {
//      cout<<a[n]<<endl;
//  }
//  return 0;
//}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 410;

struct bign
{
    int len, s[MAXN];
    bign ()
    {
        memset(s, 0, sizeof(s));
        len = 1;
    }
    bign (int num) { *this = num; }
    bign (const char *num) { *this = num; }
    bign operator = (const int num)
    {
        char s[MAXN];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }
    bign operator = (const char *num)
    {
        for(int i = 0; num[i] == '0'; num++) ;  //去前导0
        len = strlen(num);
        for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
        return *this;
    }
    bign operator + (const bign &b) const //+
    {
        bign c;
        c.len = 0;
        for(int i = 0, g = 0; g || i < max(len, b.len); i++)
        {
            int x = g;
            if(i < len) x += s[i];
            if(i < b.len) x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }
    bign operator += (const bign &b)
    {
        *this = *this + b;
        return *this;
    }
    void clean()
    {
        while(len > 1 && !s[len-1]) len--;
    }
    bign operator * (const bign &b) //*
    {
        bign c;
        c.len = len + b.len;
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < b.len; j++)
            {
                c.s[i+j] += s[i] * b.s[j];
            }
        }
        for(int i = 0; i < c.len; i++)
        {
            c.s[i+1] += c.s[i]/10;
            c.s[i] %= 10;
        }
        c.clean();
        return c;
    }
    bign operator *= (const bign &b)
    {
        *this = *this * b;
        return *this;
    }
    bign operator - (const bign &b)
    {
        bign c;
        c.len = 0;
        for(int i = 0, g = 0; i < len; i++)
        {
            int x = s[i] - g;
            if(i < b.len) x -= b.s[i];
            if(x >= 0) g = 0;
            else
            {
                g = 1;
                x += 10;
            }
            c.s[c.len++] = x;
        }
        c.clean();
        return c;
    }
    bign operator -= (const bign &b)
    {
        *this = *this - b;
        return *this;
    }
    bign operator / (const bign &b)
    {
        bign c, f = 0;
        for(int i = len-1; i >= 0; i--)
        {
            f = f*10;
            f.s[0] = s[i];
            while(f >= b)
            {
                f -= b;
                c.s[i]++;
            }
        }
        c.len = len;
        c.clean();
        return c;
    }
    bign operator /= (const bign &b)
    {
        *this  = *this / b;
        return *this;
    }
    bign operator % (const bign &b)
    {
        bign r = *this / b;
        r = *this - r*b;
        return r;
    }
    bign operator %= (const bign &b)
    {
        *this = *this % b;
        return *this;
    }
    bool operator < (const bign &b)
    {
        if(len != b.len) return len < b.len;
        for(int i = len-1; i >= 0; i--)
        {
            if(s[i] != b.s[i]) return s[i] < b.s[i];
        }
        return false;
    }
    bool operator > (const bign &b)
    {
        if(len != b.len) return len > b.len;
        for(int i = len-1; i >= 0; i--)
        {
            if(s[i] != b.s[i]) return s[i] > b.s[i];
        }
        return false;
    }
    bool operator == (const bign &b)
    {
        return !(*this > b) && !(*this < b);
    }
    bool operator != (const bign &b)
    {
        return !(*this == b);
    }
    bool operator <= (const bign &b)
    {
        return *this < b || *this == b;
    }
    bool operator >= (const bign &b)
    {
        return *this > b || *this == b;
    }
    string str() const
    {
        string res = "";
        for(int i = 0; i < len; i++) res = char(s[i]+'0') + res;
        return res;
    }
};

istream& operator >> (istream &in, bign &x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}

ostream& operator << (ostream &out, const bign &x)
{
    out << x.str();
    return out;
}

int main() {
    bign a;
  while(cin>>a)
  {
      bign c ;
      c = (a%18) ;
      d= c==0;
      cout<<d<<endl;
//      if() cout<<"Yes\n";
//      else cout<<"No\n";
  }
  return 0;
}
