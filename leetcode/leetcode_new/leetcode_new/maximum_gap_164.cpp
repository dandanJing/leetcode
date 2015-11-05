#include"top.h"

int Solution::maximumGap(vector<int>& nums){
	return 5;
}

void let_164(){
	ifstream fin;
	fin.open("let_164.txt");
	int value;
	char temp;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.maximumGap(nums)<<endl;
}