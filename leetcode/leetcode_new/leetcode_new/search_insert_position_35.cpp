#include"top.h"

int Solution::searchInsert(vector<int>& nums, int target){
	
	int result=nums.size();
	FOR(i,nums.size()){
		if(nums[i]==target){result=i;break;}
		else if(nums[i]>target){
			result=i;break;
		}
	}
	return result;
}

void let_35(){
	ifstream fin;
	fin.open("let_35.txt");
	char tempc;
	int value;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.searchInsert(nums,5)<<endl;
	cout<<sol.searchInsert(nums,2)<<endl;
	cout<<sol.searchInsert(nums,7)<<endl;
	cout<<sol.searchInsert(nums,0)<<endl;
}