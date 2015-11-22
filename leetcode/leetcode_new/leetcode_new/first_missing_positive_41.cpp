#include"top.h"

int Solution::firstMissingPositive(vector<int>& nums) {
	int pos=0,temp;
	while(pos<nums.size()){
		if(nums[pos]<=0)pos++;
		else if(nums[pos]-1==pos)pos++;
		else {
			if(nums[pos]-1>=nums.size()){pos++;continue;}

			temp=nums[nums[pos]-1];
			if(temp==nums[pos]){pos++;continue;} 

			nums[nums[pos]-1]=nums[pos];
			nums[pos]=temp;
		}
	}
	FOR(i,nums.size()){
		if(nums[i]!=i+1)return i+1;
	}
	return nums.size()+1;
}

void let_41(){
	ifstream fin;
	fin.open("let_41.txt");
	char tempc;
	int value;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.firstMissingPositive(nums)<<endl;
}