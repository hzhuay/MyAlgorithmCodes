#include<iostream>
using namespace std;
void tower(int n,char L,char M,char R,int p,int N){//把L通过M转到R 
	if(n==1){
		cout<<L<<"->"<<N-p<<"->"<<R<<endl;
		return;
	}
	tower(n-1,L,R,M,p+1,N);
	//tower(1,L,R,M,p,N);
	cout<<L<<"->"<<N-p<<"->"<<R<<endl;
	tower(n-1,M,L,R,p+1,N);
}
int main(){
	int n;
	char l,m,r;
	cin>>n>>l>>m>>r;
	tower(n,l,r,m,0,n);
	return 0;
}
