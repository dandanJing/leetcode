#include"top.h"

int Solution::search(vector<int>& nums, int target){
	int start=0,end=nums.size()-1;
	int result=-1;
	while(start<=end){
		if(nums[start]==target)return start;
		if(nums[end]==target) return end;
		if(nums[end]>nums[start]){
			if(target>nums[start] && target<nums[end]){
				start++;end--;
			}else{
				return result;
			}
		}else{
			if(target>nums[start] || target<nums[end]){
				start++;end--;
			}else return result;
		}
	}
	return result;
}

void let_33(){
	ifstream fin;
	fin.open("let_33.txt");
	char tempc=' ';
	int value;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.search(nums,0)<<endl;
}