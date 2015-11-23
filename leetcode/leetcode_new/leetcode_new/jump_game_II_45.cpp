#include"top.h"

int Solution::jump(vector<int>& nums) {
	return 5;
}

void let_45(){
	ifstream fin;
	fin.open("let_45.txt");
	char tempc;
	int value;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.jump(nums)<<endl;
}