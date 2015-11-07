#include"top.h"

int calcu(string op,int val1,int val2){
	if(op=="+")return val1+val2;
	else if(op=="-")return val1-val2;
	else if(op=="*")return val1*val2;
	else return val1/val2;
}

int Solution::evalRPN(vector<string>& tokens){
	if(!tokens.size())return 0;

	vector<int>nums;
	int value;
	FOR(i,tokens.size()){
		if((tokens[i]>="0" && tokens[i]<="9")||(tokens[i].size()>1)){
			istringstream ss(tokens[i]);
			ss>>value;
			nums.push_back(value);
		}else{
			int temp=calcu(tokens[i],nums[nums.size()-2],nums[nums.size()-1]);
			nums.pop_back();
			nums[nums.size()-1]=temp;
		}
	}
	
	return nums[0];
}

void let_150(){
	vector<string> tokens;;
	tokens.push_back("-3");
	tokens.push_back("9");
	tokens.push_back("*");
	/*tokens.push_back("/");
	tokens.push_back("+");*/
	Solution sol;
	cout<<sol.evalRPN(tokens)<<endl;
}