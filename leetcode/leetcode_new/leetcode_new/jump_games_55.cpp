#include"top.h"

//´íÎó1--[2,0,2,0,1]£¬ÆÚÍûtrue
bool Solution::canJump(vector<int>& nums){
	if(!nums.size())return false;
	int step=nums[0];
	int start=1,end=step;
	while(end<nums.size()-1){
		step=0;
		for(int i=start;i<=end;i++){
			if(nums[i]+i-end > step)step=nums[i]+i-end;
		}
		if(step>0){
			start=end+1;
			end+=step;
		}else return false;
	}
	return true;
}

void let_55(){
	ifstream fin;
	fin.open("let_55.txt");
	char tempc;
	int value;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.canJump(nums)<<endl;
}