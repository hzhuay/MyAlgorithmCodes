#include<iostream>
#include<algorithm>
using namespace std;
int a[205];
struct node{
	int c,q;
};
node dfs(int L,int R,bool flag){
	if(L==R){
		node tmp;
		tmp.q=a[L];
		tmp.c=0;
		return tmp;
	}
	if(!flag){
		node tmp1=dfs(L+1,R,!flag);
		node tmp2=dfs(L,R-1,!flag);
		tmp1.c+=a[L];
		tmp2.c+=a[R];
		if(tmp1.c-tmp1.q<tmp2.c-tmp2.q)return tmp2;
		else return tmp1;
	}else{
		node tmp1=dfs(L+1,R,!flag);
		node tmp2=dfs(L,R-1,!flag);
		tmp1.q+=a[L];
		tmp2.q+=a[R];
		if(tmp1.c-tmp1.q>tmp2.c-tmp2.q)return tmp2;
		else return tmp1;
	}
}
int main(){
	int n;
	cin>>n; 
	for(int i=1;i<=2*n;i++)cin>>a[i];
	node tmp=dfs(1,2*n,0);
	if(tmp.c>tmp.q)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
