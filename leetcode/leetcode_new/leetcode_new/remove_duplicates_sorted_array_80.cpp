#include"top.h"

int Solution::removeDuplicates(vector<int>& nums){
	int cur=0,temp;
	int count=0;
	while(cur<nums.size()){
		temp=cur+1;
		while(temp<nums.size()){
			if(nums[temp]==nums[cur])temp++;
			else break;
		}
		if(temp-cur>=2){
			nums[count++]=nums[cur];
			nums[count++]=nums[cur+1];
		}else{
			nums[count++]=nums[cur];
		}
		cur=temp;
	}
	return count;
}

void let_80(){
	ifstream fin;
	fin.open("let_80.txt");
	char tempc=' ';
	int value;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.removeDuplicates(nums)<<endl;
	FOR(i,nums.size())cout<<nums[i]<<",";
	cout<<endl;
}