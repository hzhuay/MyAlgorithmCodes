/*除法表达式：
给出一个这样的除法表达式：X1/X2/X3/X4/---/Xk,其中Xi是正整数。应当按照从左到右的顺序求和。
但是可以在表达式中嵌入括号以改变计算顺序。则判断是否可以通过添加括号，使表达式的值为整数
那么，X2必然作分母，其他所有的X都可以做分子，这也是最有可能出整数的情况。
因此题目就是判断E=X1/(X2/X3/---/Xk)是否为整数。

这里选用的方法是直接约分，约到X2与其他所有X的最大公约数，结束之后当且仅当X[2]==1时E是整数。 
*/
#include<cstdio>
int X[10005],k;
inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}//辗转相除法，得到a和b的最大公约数 
bool judge(){
	X[2]/=gcd(X[2],X[1]);
	for(int i=3;i<=k;i++)
		X[2]/=gcd(X[i],X[2]);
	return X[2]==1;
}
int main(){
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&X[i]);
	if(judge())puts("Yes");
	else puts("No");
	return 0; 
}
