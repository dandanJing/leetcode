#include"top.h"

int Solution::robII(vector<int>& nums){
	if(nums.size()==0) return 0;
	else if(nums.size()==1) return nums[0];
	else if(nums.size()==2) return max(nums[0],nums[1]);

	int temp1=0;
	int val1=0,val2=0;
	//第一个数出现
	for(int i=2;i<nums.size()-1;i++){
		if(nums[i]+val1>val2){temp1=nums[i]+val1;val1=val2;val2=temp1;}
		else {temp1=val2;val1=val2;val2=temp1;}
	}
	temp1+=nums[0];

	int temp2=0;
	int val3=0,val4=0;
	//第一个数不出现
	for(int i=1;i<nums.size();i++){
		if(nums[i]+val3>val4){temp2=nums[i]+val3;val3=val4;val4=temp2;}
		else {temp2=val4;val3=val4;val4=temp2;}
	}
	return max(temp1,temp2);
}

void let_213(){
	ifstream fin;
	fin.open("let_198.txt");
	int value;
	vector<int> nums;
	while(!fin.eof()){
		fin>>value;
		nums.push_back(value);
	}

	Solution sol;
	cout<<sol.robII(nums)<<endl;
}