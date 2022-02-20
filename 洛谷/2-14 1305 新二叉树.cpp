#include<cstdio>
char tree[30][5];
int n;
void postorder(char c){
	if(c!='*'){
		putchar(c);
		for(int i=0;i<n;i++)
			if(tree[i][0]==c){
				postorder(tree[i][1]);
				postorder(tree[i][2]);
			}
	}
}
int main(){
	scanf("%d\n",&n);
	for(int i=0;i<n;i++)scanf("%s",tree[i]);
	postorder(tree[0][0]);
	return 0;
}
