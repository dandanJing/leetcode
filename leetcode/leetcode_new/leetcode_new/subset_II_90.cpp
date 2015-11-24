#include"top.h"

vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums){
	FOR(i,nums.size()){
		int j;
		int val=nums[i];
		for(j=i-1;j>=0;j--){
			if(nums[j]>val)nums[j+1]=nums[j];
			else break;
		}
		nums[j+1]=val;
	}
	int pos=0;
	std::map<int,int>count_map;
	while(pos<nums.size()-1){
		if(nums[pos+1]==nums[pos]){
			int j=pos+2;
			for(;j<nums.size();j++){
				if(nums[j]!=nums[pos])break;
			}
			count_map.insert(pair<int,int>(pos,j-pos));
			pos=j;
		}else{
			pos++;
		}
	}
	vector<vector<int>>result;
	return result;
}

void let_90(){
	ifstream fin;
	fin.open("let_90.txt");
	char tempc;
	int val;
	
	vector<int>nums;
	while(fin.peek()!=']'){
		fin>>tempc>>val;
		nums.push_back(val);
	}
	Solution sol;
	vector<vector<int>>result=sol.subsetsWithDup(nums);
	FOR(i,result.size()){
		FOR(j,result[i].size()){
			cout<<result[i][j]<<",";
		}
		cout<<endl;
	}
	cout<<result.size()<<endl;
}