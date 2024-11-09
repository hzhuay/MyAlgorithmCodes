#include<iostream>
#define M 10005
#define N 30
using namespace std;
int num,len,coin,ans;
void up(int h,int l,int x,int y,int len);
void right(int h,int l,int x,int y,int len);
void down(int h,int l,int x,int y,int len);
void left(int h,int l,int x,int y,int len);
void up(int h,int l,int x,int y,int len){
	if(num!=0){
		if(l==y){
			ans=coin-x+h;
			cout<<ans<<endl;
			return;
		}else {
			coin+=len;
			h-=len;	
			num--;
			right(h,l,x,y,len);
			return;
		}
	}else{
		num=2;
		len--;
		up(h,l,x,y,len);
	}
}
void left(int h,int l,int x,int y,int len){
	if(num!=0){
		if(h==x){
			ans=coin-y+l;
			cout<<ans<<endl;
			return;
		}else {
			coin+=len;
			l-=len;	
			num--;
			up(h,l,x,y,len);
			return;
		}
	}else{
		num=2;
		len--;
		left(h,l,x,y,len);
	}
}
void down(int h,int l,int x,int y,int len){
	if(num!=0){
		if(l==y){
			ans=coin+x-h;
			cout<<ans<<endl;
			return;
		}else {
			coin+=len;
			h+=len;	
			num--;
			left(h,l,x,y,len);
			return;
		}
	}else{
		num=2;
		len--;
		down(h,l,x,y,len);
	}
}
void right(int h,int l,int x,int y,int len){
	if(num!=0){
		if(h==x){
			ans=coin+y-l;
			cout<<ans<<endl;
			return;
		}else {
			coin+=len;
			l+=len;	
			num--;
			down(h,l,x,y,len);
			return;
		}
	}else{
		num=2;
		len--;
		right(h,l,x,y,len);
	}
}
int main(){
	freopen("test.in","r",stdin);
	int k,n,i;
	cin>>k>>n;	
	int x[N],y[N];    
	for(i=1;i<=k;i++){
		cin>>x[i]>>y[i];
	}
	for(i=1;i<=k;i++){
		len=n-1;
		num=3;
		coin=1;
		ans=0;
		right(1,1,x[i],y[i],len);
	}
	return 0;
} 
