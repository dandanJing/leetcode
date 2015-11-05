#include"top.h"

bool Solution::containsNearbyDuplicate(vector<int>& nums, int k) {
	std::map<int,int> num_map;
	std::map<int,int>::iterator it;

	int temp_size=k+1;
	if(nums.size()<k+1)temp_size=nums.size();

	FOR(i,temp_size){
		it=num_map.find(nums[i]);
		if(it!=num_map.end()) return true;
		else num_map.insert(pair<int,int>(nums[i],1));
	}

	for(int i=k+1;i<nums.size();i++){
		num_map.erase(nums[i-k-1]);
		it=num_map.find(nums[i]);
		if(it!=num_map.end()) return true;
		else num_map.insert(pair<int,int>(nums[i],1));
	}
	return false;
}

void let_219(){
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
	cout<<sol.containsNearbyDuplicate(nums,k)<<endl;;
}