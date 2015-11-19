#include"top.h"

int Solution::maxSubArray(vector<int>& nums){
	int maxsum=0;
	if(nums.size()==0) return maxsum;
	maxsum=nums[0];
	int temp_sum=0;

	FOR(i,nums.size()){
		temp_sum+=nums[i];
		if(temp_sum>maxsum) maxsum=temp_sum;
		if(temp_sum<0)temp_sum=0;
	}
	return maxsum;
}

void let_53(){
	ifstream fin;
	fin.open("let_53.txt");
	char tempc=' ';
	int value;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		/*if(fin.peek()=='-')fin>>tempc;
		fin>>value;
		if(tempc=='-')value=-value;*/
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.maxSubArray(nums)<<endl;
}