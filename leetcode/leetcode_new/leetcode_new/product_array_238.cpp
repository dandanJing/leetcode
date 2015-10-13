#include"top.h"

vector<int> Solution::productExceptSelf(vector<int>& nums) {
	int nums_size=nums.size();
	int* temp=(int *)new(int[nums_size]);
	FOR(i,nums_size) temp[i]=1;

	FOR(i,nums_size){
		FOR(j,nums_size){
			if(j!=i)temp[j]*=nums[i];
		}
	}
	vector<int> result;
	FOR(i,nums_size) result.push_back(temp[i]);

	return result;
}

void let_238(){
	ifstream fin;
	fin.open("let_238.txt");

	vector<int>nums;
	int value;
	while(!fin.eof()){
		fin>>value;
		nums.push_back(value);
	}

	Solution sol;
	vector<int> result=sol.productExceptSelf(nums);
	FOR(i,result.size()) cout<<result[i]<<",";
	cout<<endl;
}