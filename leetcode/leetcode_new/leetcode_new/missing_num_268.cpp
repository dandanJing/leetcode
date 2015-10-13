#include"top.h"

int Solution::missingNumber(vector<int>& nums){
	int nums_size=nums.size();
	bool* hasNumVec=(bool *)new(bool[nums_size+1]);
	FOR(i,nums_size+1) hasNumVec[i]=false;
	FOR(i,nums_size){
		hasNumVec[nums[i]]=true;
	}
	FOR(i,nums_size+1){
		if(!hasNumVec[i]) return i;
	}
}

void let_268(){
	ifstream fin;
	fin.open("let_268.txt");
	vector<int>temp;
	int value;
	while(!fin.eof()){
		fin>>value;
		temp.push_back(value);
	}
	Solution sol;
	cout<<"result:"<<sol.missingNumber(temp)<<endl;
}
