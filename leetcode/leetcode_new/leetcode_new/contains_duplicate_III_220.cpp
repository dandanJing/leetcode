#include"top.h"

bool Solution::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
	int *nums_array=(int *) new int[k+1];
	
	int temp_size=k+1;
	if(nums.size()<k+1)temp_size=nums.size();

	FOR(i,temp_size){
		FOR(j,i-1){
			if(abs(nums_array[j]-nums[i])<=t) return true;
		}
		nums_array[i]=nums[i];
	}

	for(int i=k+1;i<nums.size();i++){
		for(int j=1;j<k+1;j++){
			if(abs(nums_array[j]-nums[i])<=t)return true;
			else nums_array[j-1]=nums_array[j];
		}
		nums_array[k]=nums[i];
	}
	return false;
}

void let_220(){
	vector<int> nums;
	ifstream fin;
	fin.open("let_219.txt");
	int value;
	int k;fin>>k;
	while(!fin.eof()){
		fin>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.containsNearbyAlmostDuplicate(nums,k,2)<<endl;;
}