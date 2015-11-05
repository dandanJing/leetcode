#include"top.h"

bool Solution::containsDuplicate(vector<int>& nums) {
	std::map<int,int> num_map;
	std::map<int,int>::iterator it;

	FOR(i,nums.size()){
		it=num_map.find(nums[i]);
		if(it!=num_map.end()) return true;
		else num_map.insert(pair<int,int>(nums[i],1));
	}
	return false;
}

void let_217(){
	vector<int> nums;
	ifstream fin;
	fin.open("let_217.txt");
	int value;
	while(!fin.eof()){
		fin>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.containsDuplicate(nums)<<endl;;
}