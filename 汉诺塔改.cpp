#include<iostream>
#include<vector>
using namespace std;
vector<int>a[130];
void tower(int n,char L,char M,char R){//把L通过M转到R 
	if(n==1){
		cout<<L<<"->"<<a[L].back()<<"->"<<R<<endl;
		a[R].push_back(a[L].back());
		a[L].pop_back();
		return;
	}
	tower(n-1,L,R,M);
	tower(1,L,M,R);
	tower(n-1,M,L,R);
}
int main(){
	int n;
	char l,m,r;
	cin>>n>>l>>m>>r;
	for(int i=n;i>=1;i--)a[l].push_back(i);
	tower(n,l,r,m);
	return 0;
}
