#include"top.h"

vector<int> Solution::plusOne(vector<int>& digits) {
	int upval=1;
	int temp;
	for(int i=digits.size()-1;i>=0;i--){
		temp=upval+digits[i];
		digits[i]=temp%10;
		upval=temp/10;
	}
	vector<int>result;
	if(upval){
		result.push_back(upval);
	}
	FOR(i,digits.size())result.push_back(digits[i]);
	return result;
}

void let_66(){
	ifstream fin;
	fin.open("let_66.txt");
	char tempc;
	int val;
	
	vector<int>digits;
	while(fin.peek()!=']'){
		fin>>tempc>>val;
		digits.push_back(val);
	}
	Solution sol;
	vector<int> result=sol.plusOne(digits);
	FOR(i,result.size())cout<<result[i]<<",";
	cout<<endl;
}