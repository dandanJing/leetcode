#include"top.h"

int Solution::minSubArrayLen(int s, vector<int>& nums){
	int result=0x7fffffff;
	int temp_sum=0;
	int count=0;

	FOR(i,nums.size()){
		if(count < result-1){
			temp_sum += nums[i];
			count++;
		}else{
			temp_sum += nums[i];
			temp_sum -= nums[i-count];
		}

		while(temp_sum >= s){
			result=count--;
			temp_sum -= nums[i-count];
		}
		if(count==0) break;
	}

	if(result==0x7fffffff) return 0;
	return result;
}

void let_209(){
	ifstream fin;
	fin.open("let_209.txt");
	int s;fin>>s;
	int value;
	vector<int> nums;
	while(!fin.eof()){
		fin>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.minSubArrayLen(s,nums)<<endl;
}