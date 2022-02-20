#include<cstdio>
int p[5];
int main(){
	int pa,pb,a=0,b=0;
	scanf("%d%d%d%d%d",&pa,&pb,&p[0],&p[1],&p[2]);
	int sum=p[0]+p[1]+p[2];
	for(int i=0;i<3;i++)
		if(p[i]==0)a++;
		else b++;
	if(sum==0)printf("The winner is a: %d + 3",pa);
	else if(sum==3)printf("The winner is b: %d + 3",pb);
	else if(pa>pb)printf("The winner is a: %d + %d",pa,a);
	else printf("The winner is b: %d + %d",pb,b);
	return 0;
}
