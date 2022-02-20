#include<cstdio>
#include<cstring>
struct People{
	char name[20];
	int n,ini,give,gain;
}p[15];
int np;
inline int find(){
	char ser[20];
	scanf("%s",ser);
	for(int i=0;i<np;i++)
		if(strcmp(ser,p[i].name)==0)
			return i;
}
int main(){
	scanf("%d",&np);
	for(int i=0;i<np;i++){
		scanf("%s",p[i].name);
		p[i].gain=0;
	}
	for(int T=0;T<np;T++){
		int i=find();
		scanf("%d %d\n",&p[i].ini,&p[i].n);
		p[i].give=p[i].n==0?0:p[i].ini/p[i].n*p[i].n;
		for(int K=0;K<p[i].n;K++){
			int j=find();
			p[j].gain+=p[i].ini/p[i].n;	
		}
	}
	for(int i=0;i<np;i++)printf("%s %d\n",p[i].name,p[i].gain-p[i].give);
	return 0;
} 
