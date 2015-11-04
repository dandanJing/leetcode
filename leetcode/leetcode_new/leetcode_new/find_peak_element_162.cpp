#include"top.h"

int Solution::findPeakElement(vector<int>& nums){
	if(!nums.size()) return -1;
	if(nums.size()==1) return 0;
	if(nums.size()==2) {
		if(nums[0]>nums[1])return 0;
		else return 1;
	}
	if(nums[0]>nums[1])return 0;
	if(nums[nums.size()-1]>nums[nums.size()-2])return nums.size()-1;
	for(int i=1;i<nums.size()-1;i++){
		if(nums[i+1]<nums[i])return i;
	}
	return -1;
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