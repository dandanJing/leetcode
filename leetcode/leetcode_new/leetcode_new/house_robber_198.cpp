#include"top.h"

int robHouse(vector<int> nums, int start_pos){
	if(start_pos==nums.size()-1) return nums[start_pos];
	else if(start_pos>=nums.size()) return 0;

	int result=0;
	int val1=robHouse(nums,start_pos+1);
	int val2=nums[start_pos]+robHouse(nums,start_pos+2);
	if(val1>val2) result=val1;
	else result=val2;

	return result;
}

int Solution::rob(vector<int>& nums){
	return robHouse(nums,0);
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