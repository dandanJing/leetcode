#include"top.h"

int Solution::removeElement(vector<int>& nums, int val){
	int size=0;
	FOR(i,nums.size()){
		if(nums[i]==val)continue;
		else{
			nums[size++]=nums[i];
		}
	}
	return size;
}

void let_27(){
	ifstream fin;
	fin.open("let_27.txt");
	char tempc;
	int value;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.removeElement(nums,5)<<endl;
	cout<<sol.removeElement(nums,2)<<endl;
}