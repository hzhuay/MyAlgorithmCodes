#include<iostream>
using namespace std;
void tower(int n,char L,char M,char R){
	if(n==1){
		cout<<L<<"->"<<R<<endl; 
		return;
	}
	tower(n-1,L,R,M);
	tower(1,L,M,R);
	tower(n-1,M,L,R);
}
int main(){
	int n;
	cin>>n;
	tower(n,'A','B','C');
	return 0;
}
