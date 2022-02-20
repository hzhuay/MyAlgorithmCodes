#include<iostream>
#include<cstdio>
using namespace std;
bool solve(int& W){
	int W1,D1,W2,D2;
	bool b1=true,b2=true;
	cin>>W1>>D1>>W2>>D2;
	if(!W1)b1=solve(W1);
	if(!W2)b2=solve(W2);
	W=W1+W2;
	return b1&&b2&&(W1*D1==W2*D2);
}
int main(){
	//freopen("in.txt","r",stdin);
	int T,W;
	cin>>T;
	while(T--){
		if(solve(W))puts("YES");
		else puts("NO");
		if(T)puts("");
	}
	return 0;
}
