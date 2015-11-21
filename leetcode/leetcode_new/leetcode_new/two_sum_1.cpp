#include"top.h"

vector<int> Solution::twoSum(vector<int>& nums, int target){
	std::map<int,int> map_int;
	std::map<int,int>::iterator it;

	vector<int> result;
	int temp;
	FOR(i,nums.size()){
		temp=target-nums[i];
		it=map_int.find(temp);
		if(it==map_int.end()){
			map_int.insert(pair<int,int>(nums[i],i));
		}else{
			result.push_back(it->second+1);
			result.push_back(i+1);
			break;
		}
	}
	return result;
}

void let_1(){
	ifstream fin;
	fin.open("let_1.txt");
	vector<int> nums;
	char tempc;
	int value;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums.push_back(value);
	}
	Solution sol;
	vector<int> result=sol.twoSum(nums,9);
	FOR(i,result.size())cout<<result[i]<<",";
	cout<<endl;
}