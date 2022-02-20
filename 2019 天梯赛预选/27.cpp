#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Stu{
	char c[20];
	int s;
	int rank;
}p[10005];
bool cmp(const Stu a,const Stu b){
	if(a.s!=b.s)return a.s>b.s;
	else{
		int len=min(strlen(a.c),strlen(b.c));
		for(int i=0;i<len;i++)
			if(a.c[i]!=b.c[i])return a.c[i]<b.c[i];
		return strlen(a.c)<strlen(b.c);
	}
}
int main(){
	int N,G,K,sum=0,cnt=0;
	scanf("%d%d%d",&N,&G,&K);
	for(int i=0;i<N;i++)
		scanf("%s%d",p[i].c,&p[i].s);
	sort(p,p+N,cmp);
	for(int i=0;i<N;i++){
		if(p[i].s>=G)sum+=50;
		else if(p[i].s>=60)sum+=20;
		if(i==0)p[i].rank=1;
		else if(p[i].s==p[i-1].s)p[i].rank=p[i-1].rank;
		else p[i].rank=i+1;
	}
	printf("%d\n",sum);
	for(int i=0;i<N;i++){
		if(p[i].rank<=K)
			printf("%d %s %d\n",p[i].rank,p[i].c,p[i].s);
	}
	return 0;
}
