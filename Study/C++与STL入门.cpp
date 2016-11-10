#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
//template<typename T>
//struct Point{
//T  x,y;
//Point(T x=0,T y=0):x(x),y(y){}
//};
//template<typename T>
//Point<T> operator +(const Point<T>& A,const Point<T>& B)
//{
//    return Point<T>(A.x+B.x,A.y+B.y);
//}
//template<typename T>
//ostream& operator << (ostream & out,const Point<T> & p)
//{
//    out << " ("<<p.x<<","<<p.y<<")";
//    return out;
//}
//template<typename T>
//T sum(T* begin,T* end)
//{
//    T *p = begin;
//    T ans = 0;
//    for(T *p = begin;p != end;p++)
//        ans = ans + *p;
//    return ans;
//}
//int main()
//{
//    double a[] = {1.1,2.2,3.3,4.4};
//    cout<< sum(a,a+4)<<endl;
//    Point<double> b[] ={Point<double>(1.1,2),Point<double>(3,4),Point<double>(5,6),Point<double>(7,8)};
//    cout<< sum(b,b+4)<<endl;
//}

//typedef struct tagStudentInfo
//{
//  int nID;
//  string strName;
//  bool operator <(tagStudentInfo const& _A) const//ÉýÐòÅÅÁÐ
//
//    {
//     if(nID<_A.nID)
//     return true;
//     if(nID == _A.nID)
//     return strName.compare(_A.strName) < 0;
//        return false;
//    }
//}sInfo,*PsInfo;
//
//int main()
//{
//  set<sInfo>setS;
//  sInfo stuInfo;
//
//  stuInfo.nID = 10;
//  stuInfo.strName = "test1";
//  setS.insert(stuInfo);
//
//  stuInfo.nID = 20;
//  stuInfo.strName = "test2";
//  setS.insert(stuInfo);
//
//  set<sInfo>::iterator sIter;
//  for(sIter=setS.begin(); sIter!=setS.end(); sIter++)
//  {
//    cout <<(*sIter).nID <<" "<< (*sIter).strName << endl;
//  }
//
//  set<int>a;
//  set<int>b;
//  set<int>c;
//  set<int>d;
//  set<int>e;
//
//  a.insert(1);
//  a.insert(2);
//  a.insert(3);
//  a.insert(4);
//  a.insert(5);
//
//  b.insert(3);
//  b.insert(4);
//  b.insert(5);
//
//  set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
//  set<int>::iterator s;
//  for(s=c.begin(); s!=c.end(); s++)
//  {
//    cout <<(*s)<<",";
//  }
//  cout << endl;
//
//  set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(d, d.begin()));
//  for(s=d.begin(); s!=d.end(); s++)
//  {
//    cout <<(*s) <<",";
//  }
//  cout << endl;
//
//  set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(e, e.begin()));
//  for(s=e.begin(); s!=e.end(); s++)
//  {
//    cout <<(*s)<<",";
//  }
//  cout <<endl;
//
//  return 0;
//}
