#include"top.h"

void Solution::moveZeroes(vector<int>& nums){
	int cur_pos=0;
	FOR(i,nums.size()){
		if(nums[i]) nums[cur_pos++]=nums[i];
	}
	for(int i=cur_pos;i<nums.size();i++)nums[i]=0;
}

void let_283(){
	ifstream fin;
	fin.open("let_283.txt");
	vector<int> input_nums;
	int temp;
	while(!fin.eof()){
		fin>>temp;
		input_nums.push_back(temp);
	}
	cout<<"initial:"<<endl;
	FOR(i,input_nums.size())cout<<input_nums[i]<<" ";
	Solution sol;
	sol.moveZeroes(input_nums);
	cout<<"end:"<<endl;
	FOR(i,input_nums.size())cout<<input_nums[i]<<" ";
	cout<<endl;
}