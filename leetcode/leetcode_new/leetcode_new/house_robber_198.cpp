#include"top.h"

int Solution::rob(vector<int>& nums){
	if(nums.size()==0) return 0;
	else if(nums.size()==1) return nums[0];

	for(int i=1;i<nums.size();i++){
		if(i==1 && nums[0]>nums[1]){nums[1]=nums[0];continue;}
		else if(i==1) continue;

		if(nums[i]+nums[i-2]>nums[i-1])nums[i]+=nums[i-2];
		else nums[i]=nums[i-1];
	}
	return nums[nums.size()-1];
}

void let_198(){
	ifstream fin;
	fin.open("let_198.txt");
	int value;
	vector<int> nums;
	while(!fin.eof()){
		fin>>value;
		nums.push_back(value);
	}

	Solution sol;
	cout<<sol.rob(nums)<<endl;
}