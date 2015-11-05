#include"top.h"

vector<int> Solution::maxSlidingWindow(vector<int>& nums, int k){
	vector<int> result;
	int nums_size=nums.size();
	
	if(k>nums_size||nums_size==0) return result;

	int max_val=0x80000000;
	for(int i=0;i<=nums_size-k;i++){
		max_val=0x80000000;
		for(int j=i;j<i+k;j++){
			if(nums[j]>max_val) max_val=nums[j];
		}
		result.push_back(max_val);
	}
	
	return result;
}

void let_239(){
	vector<int> nums;
	fstream fin;
	fin.open("let_239.txt");
	int k;fin>>k;
	int temp;
	while(!fin.eof()){
		fin>>temp;
		nums.push_back(temp);
	}
	Solution sol;
	vector<int> result=sol.maxSlidingWindow(nums,k);
	FOR(i,result.size()) cout<<result[i]<<",";
	cout<<endl;
}