#include"top.h"

bool Solution::isValid(string s){
	vector<char>char_vec;
	FOR(i,s.size()){
		if(s[i]==' ')continue;
		if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
			char_vec.push_back(s[i]);
		}else if(char_vec.size()){
			char temp=char_vec.back();
			char_vec.pop_back();
			if(temp=='[' && s[i]==']')continue;
			if(temp=='(' && s[i]==')')continue;
			if(temp=='{' && s[i]=='}')continue;
			return false;
		}else{
			return false;
		}
	}
	if(char_vec.size()) return false;
	return true;
}

void let_20(){
	Solution sol;
	cout<<sol.isValid("()]{}")<<endl;
}