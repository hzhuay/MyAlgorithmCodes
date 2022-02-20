#include<iostream>
#define M 10005
#define N 30
using namespace std;
int coin[M][M];
bool mark[M][M];
int num=1;
void up(int i,int j);
void right(int i,int j);
void down(int i,int j);
void left(int i,int j);
void up(int i,int j){
	mark[i][j]=0;
	coin[i][j]=num++;
	if(!mark[i-1][j]&&!mark[i][j+1])return;
	if(mark[i-1][j]){
		up(i-1,j);
		return;
	}else {
	right(i,j+1);	
	return;
	}
}
void left(int i,int j){
	mark[i][j]=0;
	coin[i][j]=num++;
	if(!mark[i][j-1]&&!mark[i-1][j])return;
	if(mark[i][j-1]){
		left(i,j-1);
		return;
	}else {
	up(i-1,j);
	return;
	}
}
void down(int i,int j){
	mark[i][j]=0;
	coin[i][j]=num++;
	if(!mark[i+1][j]&&!mark[i][j-1])return;
	if(mark[i+1][j]){
		down(i+1,j);
		return;
	}else {
		left(i,j-1);
		return;
	}
}
void right(int i,int j){
	mark[i][j]=0;
	coin[i][j]=num++;
	if(!mark[i][j+1]&&!mark[i+1][j])return;
	if(mark[i][j+1]){
		right(i,j+1);
		return;
	}else {
		down(i+1,j);
		return ;
	}
}
int main(){
	int k,n,i,j;
	cin>>k>>n;	
	int x[N],y[N];    
	for(i=0;i<=N;i++){
		x[i]=0;
		y[i]=0;
	}
	for(i=1;i<=k;i++){
		cin>>x[i]>>y[i];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			mark[i][j]=1;
		}		
	}
	right(1,1);
	for(i=1;i<=k;i++){
		if(x[i])cout<<coin[x[i]][y[i]]<<endl;
	}
	return 0;
} 
