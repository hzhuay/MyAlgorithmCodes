#include<bits/stdc++.h>
using namespace std;
int getPriority(char c) {
	if(c == '@'){
		return 3;
	}else if(c=='x'){
		return 2;
	}else if(c=='+'){
		return 1;
	}
}

void operate(stack<int>& nums, stack<char>& ops){
	char op = ops.top();
	ops.pop();
	int a = nums.top(); nums.pop();
	int b = nums.top(); nums.pop();
	int res = 0;
	if(op=='+'){
		res = a + b;
    }else if(op=='@'){
		res = b | (a + b);
	}else if(op=='x'){
		res = a * b;
	}
	
	//printf("%d %c %d = %d\n", b, op, a, res); 
	nums.push(res);
}


inline bool isDigit(char c){
	return '0'<=c && c<='9'; 
}

int calculate(string& s){
	stack<int> nums;
	stack<char> ops;
	
	for(int i=0; i<s.size(); i++){
		//cout<<s[i]<<endl;
		if(isDigit(s[i])){
			int tmp = 0;
			while(isDigit(s[i])){
				tmp = tmp*10 + s[i++]-'0';
			}
			i--;
			nums.push(tmp);
		}else {
			//if(!ops.empty())
				//printf("ÓÅÏÈ¼¶ %c=%d, %c=%d\n", ops.top(), getPriority(ops.top()), s[i], getPriority(s[i]));
			if(!ops.empty() && getPriority(s[i]) < getPriority(ops.top())){
			
				while(!ops.empty() && getPriority(s[i]) < getPriority(ops.top())){
					operate(nums, ops);
				} 
//				operate(nums, ops);
			}
			ops.push(s[i]);
		}
	}
	while(!ops.empty()){
		operate(nums, ops);
	} 
//	cout<<nums.top()<<" "<<nums.size()<<" "<<ops.size()<<endl;
	return nums.top();
}

int main(){
	// 
	string exp;
    cin>>exp;
	cout<<calculate(exp)<<endl;
	return 0;
} 
