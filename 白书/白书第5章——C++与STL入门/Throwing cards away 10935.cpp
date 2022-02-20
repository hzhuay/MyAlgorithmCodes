#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
queue<int>q;
int main(){
	//freopen("out.txt","w",stdout);
	int n;
	while(cin>>n,n!=0){
		if(n==1){printf("Discarded cards:\nRemaining card: 1\n");continue;}
		printf("Discarded cards");
		for(int i=1;i<=n;i++)
			q.push(i);
		for(int i=1;i<n;i++){
			printf("%c %d",",:"[i==1],q.front());
			q.pop();
			q.push(q.front());
			q.pop();
		}
		printf("\nRemaining card: %d\n",q.front());
		q.pop();
	}
	return 0;
}
