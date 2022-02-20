#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
deque<int>q;
int p[305],o[305];
inline void print(){
	deque<int>::iterator iter;
	for(iter=q.begin();iter!=q.end();iter++)
		printf("%d ",*iter);
	puts("");
}
inline void order1(){
	int tmp1=q.front();q.pop_front();
	int tmp2=q.front();q.pop_front();
	q.push_front(tmp1);
	q.push_front(tmp2);
}
inline void order2(){
	int tmp=q.front();q.pop_front();
	q.push_back(tmp);
}
int main(){
	int n;
	while(scanf("%d",&n)&&n){
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);
			q.push_back(p[i]);
		}
		//int tmp;
		//while(scanf("%d",&tmp)){
		char tmp[100];
		scanf("%s",tmp);
		for(int i=0;i<strlen(tmp);i++){
			if(tmp[i]=='1'){
				order1();
				print();	
			}else if(tmp[i]=='2'){
				order2();
				print();
			}
		}
		memset(p,0,sizeof(p));
		q.clear();
	}
	return 0;
} 
