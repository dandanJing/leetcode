#include"top.h"

int Solution::findPeakElement(vector<int>& nums){
	return 5;
}

void let_162(){
	ifstream fin;
	fin.open("let_162.txt");
	int value;
	char temp;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.findPeakElement(nums)<<endl;
}