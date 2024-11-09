#include<set>
#include<cstdio>
#include<iostream>
using namespace std;
set<int>s;
int main(){
	int N;
	scanf("%d",&N);
	while(N--){
		int p,k;
		scanf("%d%d",&p,&k);
		if(p==0)s.insert(k);
		else if(p==1)s.erase(k);
		else if(p==2){
			set<int>::iterator i =s.end();
			while(k--)i--;
			printf("%d\n",*i);
		}
	}
	return 0;
}

