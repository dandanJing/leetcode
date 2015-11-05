#include"top.h"

int Solution::titleToNumber(string s){
	int result=0;
	int base=1;
	for(int i=s.size()-1;i>=0;i--){
		result+=base*(s[i]-'A'+1);
		base*=26;
	}
	return result;
}

void let_171(){
	Solution sol;
	cout<<sol.titleToNumber("AC")<<endl;
}