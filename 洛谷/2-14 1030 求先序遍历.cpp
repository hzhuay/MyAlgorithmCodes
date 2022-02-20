#include<cstdio>
#include<cstring>
char in[10],post[10],tree[5][10];
void build_tree(int l1,int r1,int l2,int r2){
	if(l1>r1)return;//空树 
	char root=post[r2];
	printf("%c",root);
	int p=l1;
	while(in[p]!=root)p++;
	int cnt=p-l1;//左子树的节点数
	build_tree(l1,p-1,l2,l2+cnt-1);
	build_tree(p+1,r1,l2+cnt,r2-1);
}
int main(){
	scanf("%s%s",in,post);
	build_tree(0,strlen(in)-1,0,strlen(post)-1);
	return 0;
}
