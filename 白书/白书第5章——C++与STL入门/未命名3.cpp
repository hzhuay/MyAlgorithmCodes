#include<string>
#include<iostream>
using namespace std;
int main(){
	string a,b,c;
	a="123456789";
	b=a.substr(4);
	c=a.substr(0,4);
	cout<<a<<'\n'<<b<<"\n"<<c<<endl;
	return 0;
}
