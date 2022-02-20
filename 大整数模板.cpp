#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
const int maxn = 85,MOD=10000;
using namespace std;
struct BigInteger{
    int len, s[maxn];
    BigInteger() {
        memset(s,0,sizeof(s));
        len = 1;
    }

    BigInteger operator + (const BigInteger& b) const{
        BigInteger c;c.len=max(len,b.len);int x=0;
        for(int i=0;i<c.len;i++) {
            c.s[i]=s[i]+b.s[i]+x;
            x=c.s[i]/MOD;
            c.s[i]%=MOD;
        }
        if(x>0)c.s[c.len++]=x;
        return c;
    }
 
    BigInteger operator * (const int &b) {
    	BigInteger c; c.len=len;int x=0;
    	for(int i=0;i<c.len;i++){
    		c.s[i]=s[i]*b+x;
    		x=c.s[i]/MOD;
    		c.s[i]%=MOD;
		}
		while(x>0)c.s[c.len++]=x%MOD,x/=MOD;
		return c;
	}

    bool operator < (const BigInteger& b) const{
        if(len != b.len) return len < b.len;
        for(int i = len-1; i >= 0; i--)
            if(s[i] != b.s[i])
                return s[i] < b.s[i];
        return false;
    }

}dp[85][855],B[85],ans;

BigInteger max(const BigInteger& A, const BigInteger& B){
	if(A<B)return B;
	else return A;
}
int A[1005];
int main(){
	B[0].s[0]=1;
	for(int i=1;i<=80;i++)B[i]=B[i-1]*2;
	int N,M;
	scanf("%d%d",&N,&M);
	for(int k=0;k<N;k++){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=M;i++)scanf("%d",&A[i]);
		for(int i=1;i<=M;i++){
            for(int j=M;j>=i;j--){
            	dp[i][j]=max(dp[i][j],dp[i-1][j]+B[i+M-j-1]*A[i-1]);
            	dp[i][j]=max(dp[i][j],dp[i][j+1]+B[i+M-j-1]*A[j+1]);
            }
        }
        BigInteger tmp;
        for(int i=1;i<=M;i++)tmp=max(tmp,dp[i][i]+B[M]*A[i]);
        ans=ans+tmp;
	}
	if(ans.len==0)puts("0");
	else{
		printf("%d",ans.s[ans.len-1]);
		for(int i=ans.len-2;i>=0;i--){
			if(ans.s[i]==0){
				printf("0000");
				continue;
			}
			for(int j=10;j*ans.s[i]<MOD;j*=10)printf("0");
        	printf("%d",ans.s[i]);
		}	
	}
	return 0;
} 
