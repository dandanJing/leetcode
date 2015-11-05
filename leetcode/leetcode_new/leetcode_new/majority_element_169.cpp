#include"top.h"
int Solution::majorityElement(vector<int>& nums){
	if(nums.size()==1) return nums[0];

	int thresh = nums.size()/2;

	std::map<int,int> nums_map;
	std::map<int,int>::iterator it;
	for(int i=0;i<nums.size();i++){
		it=nums_map.find(nums[i]);
		if(it==nums_map.end()){
			nums_map.insert(pair<int,int>(nums[i],1));
		}else{
			it->second++;
			if(it->second>thresh) return it->first;
		}
	}
}

void let_169(){
	vector<int> nums;
	nums.push_back(1);
	Solution sol;
	cout<<sol.majorityElement(nums)<<endl;
}