#include"top.h"

bool Solution::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
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
	cout<<sol.containsNearbyAlmostDuplicate(nums,k,1)<<endl;;
}