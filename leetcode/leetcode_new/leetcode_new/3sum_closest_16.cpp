#include"top.h"

int Solution::threeSumClosest(vector<int>& nums, int target){
	if(nums.size()<3)return 0;

	sort(nums.begin(),nums.end());
	int distance=abs(nums[0]+nums[1]+nums[2]-target);
	int val=nums[0]+nums[1]+nums[2],temp;
	for(int i=0;i<nums.size()-2;i++){
		int j=i+1;int k=nums.size()-1;
		while(j<k){
			int tsum=nums[i]+nums[j]+nums[k];
    	    if(tsum<target){
    	        j++;
    	    }else if(tsum>target){
    	        k--;
    	    }else{
				return target;
			}
			if(abs(tsum-target)<distance){
				distance=abs(tsum-target);
				val=tsum;
			}
		}
	}
	return val;
}

void let_16(){
	ifstream fin;
	fin.open("let_16.txt");
	char tempc;
	int value;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.threeSumClosest(nums,1)<<endl;
}