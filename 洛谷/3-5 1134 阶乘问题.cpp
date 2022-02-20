#include<cstdio>
int a[4]={6,8,4,2};
int main(){
    int n,ans=1;
	scanf("%d",&n);
    while(n>0){
        for(int i=1;i<=n%10;i++)
            if(i!=5)ans=ans*i%10;
        n=n/5;
        ans=ans*a[n%4]%10;
    }
    printf("%d",ans);
    return 0;
}
