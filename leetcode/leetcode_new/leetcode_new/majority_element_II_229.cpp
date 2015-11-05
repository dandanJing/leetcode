#include"top.h"

vector<int> Solution::majorityElement(vector<int>& nums){
	vector<int> result;
	std::map<int,int> numsCount;
	std::map<int,int>::iterator it;
	FOR(i,nums.size()){
		it=numsCount.find(nums[i]);
		if(it==numsCount.end()) numsCount.insert(pair<int,int>(nums[i],1));
		else it->second++;
	}
	int min_count=nums.size()/3+1;
	for(it=numsCount.begin();it!=numsCount.end();it++){
		if(it->second >= min_count) result.push_back(it->first);
	}
	return result;
}

void let_229(){
	ifstream fin;
	fin.open("let_229.txt");
	int value;
	vector<int>nums;
	while(!fin.eof()){
		fin>>value;
		nums.push_back(value);
	}
	Solution sol;
	vector<int> result=sol.majorityElement(nums);
	FOR(i,result.size()) cout<<result[i]<<",";
	cout<<endl;
}