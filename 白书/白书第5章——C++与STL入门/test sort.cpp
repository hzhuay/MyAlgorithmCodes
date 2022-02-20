#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
using namespace std;
void fill_random_int(vector<int>& v,int cnt){//随机数生成 
	v.clear();
	for(int i=0;i<cnt;i++)
		v.push_back(rand());
}
vector<int> fill_random_int(int cnt){
	vector<int> v;
	for(int i=0;i<cnt;i++)
		v.push_back(rand());
	return v;
}//这样会进行不必要的复制 ,函数可以重载 
void test_sort(vector<int>& v){
	sort(v.begin(),v.end());
	for(int i=0;i<v.size()-1;i++)
		assert(v[i]<=v[i+1]);//当表达式为真时无变化，为假时强行终止程序并给出错误提示 
}
int main(){
	vector<int>v;
	fill_random_int(v,1000000);
	test_sort(v); 
	return 0;
}
