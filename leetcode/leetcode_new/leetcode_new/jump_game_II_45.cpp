#include"top.h"

//´íÎó1£º[7,0,9,6,9,6,1,7,9,0,1,2,9,0,3]£¬ÆÚÍû2
int Solution::jump(vector<int>& nums) {
	if(!nums.size())return 0;
	if(nums.size()==1) return 0;
	if(nums[0]>=nums.size()-1) return 1;

	int step=0;
	int last_val=0;
	int max_val=nums[0];
	int temp;
	while(1){
		step++;
		if(max_val<=last_val) break;

		temp=max_val;
		for(int i=last_val+1;i<=max_val;i++){
			if(nums[i]+i>=nums.size()-1){return step+1;}
			else if(nums[i]+i>temp)temp=nums[i]+i;
		}
		last_val=max_val;
		max_val=temp;
	}
	return step;
}

void let_45(){
	ifstream fin;
	fin.open("let_45.txt");
	char tempc;
	int value;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.jump(nums)<<endl;
}