//本质：欧拉图 
#include<cstdio>
int edge[130][130],in[130],ans;
char str[10000];
void dfs(int i){
	//str[ans++]=i;//看似可以，但是不行，相同字符对会被分开 
	for(int j='A';j<='z';j++)
		if(edge[i][j]){
			edge[i][j]--;
			edge[j][i]--;
			dfs(j);
		}
	str[++ans]=i;
}
int main(){
//	freopen("in.txt","r",stdin); 
	int n,odd=0,st=0;
	char c[5];
	scanf("%d\n",&n);
	for(int i=0;i<n;i++){
		scanf("%s",c);
		edge[c[0]][c[1]]++;
		edge[c[1]][c[0]]++;
		in[c[0]]++;in[c[1]]++; 		
	}
	for(int i='A';i<='z';i++)//找奇点 
		if(in[i]%2==1){
			odd++;
			if(!st)st=i;
		}
	if(!st)//找不到奇点，找最小的偶点 
		for(int i='A';i<='z';i++)
			if(in[i]){st=i;break;}		
	
	if(odd&&odd!=2)printf("No Solution");
	else{
		dfs(st);
		if(ans<=n)printf("No Solution");
		else //for(int i=ans;i>0;i--)printf("%c",str[i]);
			printf("%s",str);
	}
	return 0;
}
