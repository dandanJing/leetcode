#include"top.h"

bool Solution::searchII(vector<int>& nums, int target){
	int start=0,end=nums.size()-1;
	
	while(start<=end){
		if(nums[start]==target)return true;
		if(nums[end]==target) return true;
		if(nums[end]>nums[start]){
			if(target>nums[start] && target<nums[end]){
				start++;end--;
			}else{
				return false;
			}
		}else if(nums[end]==nums[start]){
			start++;end--;
		}else{
			if(target>nums[start] || target<nums[end]){
				start++;end--;
			}else return false;
		}
	}
	return false;
}

void let_81(){
	ifstream fin;
	fin.open("let_81.txt");
	char tempc=' ';
	int value;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.searchII(nums,3)<<endl;
}