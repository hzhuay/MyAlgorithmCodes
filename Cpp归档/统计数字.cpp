#include<iostream>
#include<algorithm>
#define M 10005
#define N 200005 
using namespace std;
int A[N],ans[M],num[M];
int main(){
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>A[i];
	}
	sort(A+1,A+n+1);
	ans[1]=1;
	num[1]=A[1];
	for(i=2,j=1;i<=n;i++){
		if(A[i]==A[i-1]){
			ans[j]++;
		}
		else{
			j++;
			num[j]=A[i];
			ans[j]=1;
		}
	}
	for(i=1;i<=j;i++){
		cout<<num[i]<<" "<<ans[i]<<endl;
	}
	return 0;
}
