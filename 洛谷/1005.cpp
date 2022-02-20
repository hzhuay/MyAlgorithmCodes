#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<cstdlib>
using namespace std;
const int maxn=1005;  
int A[maxn];
struct bign{
    int d[maxn], len;
    
    void clean(){while(len>1 && !d[len-1])len--;} 

	bign(){memset(d,0,sizeof(d));len = 1;}
	bign(int num){*this=num;} 
	bign(char* num){*this=num;}
	bign operator = (const char* num){
		memset(d,0,sizeof(d));
		len=strlen(num);
		for(int i=0;i<len;i++)
			d[i]=num[len-1-i]-'0';
		clean();
		return *this;
	}
	bign operator = (int num){
		char s[20];
		sprintf(s,"%d",num);
		*this=s;
		return *this;
	}
	
	bign operator + (const bign& b){
		bign c=*this;
		int i;
		for(i=0;i<b.len;i++){
			c.d[i]+=b.d[i];
			if(c.d[i]>9)c.d[i]%=10,c.d[i+1]++;
		}
		while(c.d[i]>9)c.d[i++]%=10,c.d[i]++;
		c.len=max(len, b.len);
		if(c.d[i]&&c.len<=i)c.len=i+1;
		return c;
	}
	bign operator * (const bign& b)const{
		bign c;
		c.len=len+b.len;
		for(int j=0;j<b.len;j++)
			for(int i=0;i<len;i++)
				c.d[i+j]+=d[i]*b.d[j];
		for(int i=0;i<c.len-1;i++)
			c.d[i+1]+=c.d[i]/10,c.d[i]%=10;
		c.clean();
		return c;
	}
	bign operator += (const bign& b){
		*this=*this+b;
		return *this;
	}
	
	bool operator <(const bign& b) const{
		if(len!=b.len)return len<b.len;
		for(int i=len-1;i>=0;i--)
			if(d[i]!=b.d[i])return d[i]<b.d[i];
		return false;
	}
	bool operator >(const bign& b) const{return b<*this;}
	bool operator<=(const bign& b) const{return !(b<*this);}
	bool operator>=(const bign& b) const{return !(*this<b);}
	bool operator!=(const bign& b) const{return b<*this || *this<b;}
	bool operator==(const bign& b) const{return !(b<*this) && !(b>*this);}

    string str() const{
		char s[maxn]={};
		for(int i=0;i<len;i++)s[len-1-i]=d[i]+'0';
		return s;
	}
}B[85];
bign max(const bign &a, const bign &b) {
    return a<b?b:a;
}
ostream& operator << (ostream& out, const bign& x)  
{  
    out << x.str();  
    return out;  
}
int main(){
	for(int i=1;i<=80;i++)
		B[i]=B[i-1]*2;
	int N,M;
	bign ans=0;
	scanf("%d%d",&N,&M);
	while(N--){
		bign dp[maxn][maxn];
		for(int i=1;i<=M;i++)scanf("%d",&A[i]);
		for(int i=1;i<=M;i++){
			for(int j=M;j>=i;j--){
				dp[i][j]=max(dp[i][j],dp[i-1][j]+B[i+M-j-1]*A[i-1]);
				dp[i][j]=max(dp[i][j],dp[i][j+1]+B[i+M-j-1]*A[j+1]);
			}
		}
		bign tmp=0;
		for(int i=1;i<=M;i++)
			tmp=max(tmp,dp[i][i]+B[M]*A[i]);
		cout<<tmp;
	}
	cout<<ans;
	return 0;
}
