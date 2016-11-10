#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
char bookname[100];
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
	string brower;
	stack<string> backst,forst;
	string command,name;
	backst.push("The C Programming Language");
	while (cin>>command,command!="QUIT")
	{
		if (command == "GET")
		{
		    getchar();
		    gets(bookname);
			name = bookname;
			backst.push(name);
			cout<<name<<endl;
		    while(!forst.empty()) forst.pop();
		}
		else if (command == "RETURN")
		{
			if (backst.size()==1)
			{
				cout<<"OVER"<<endl;
			}
			else
			{
				name = backst.top();
				forst.push(name);
				backst.pop();
				name = backst.top();
				cout<<name<<endl;
			}

		}
		else if (command == "ADVANCE")
		{
			if (forst.size()==0)
			{
				cout<<"OVER"<<endl;
			}
			else
			{
				name= forst.top();
				backst.push(name);
				forst.pop();
				cout<<name<<endl;
			}
		}
	}
	return 0;
}

