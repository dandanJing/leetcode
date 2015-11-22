#include"top.h"

void Solution::nextPermutation(vector<int>& nums) {
	int temp;
	for(int i=nums.size()-1;i>=0;i--){
		for(int j=nums.size()-1;j>i;j--){
			if(nums[j]>nums[i]){
				temp=nums[i];
				nums[i]=nums[j];
				nums[j]=temp;
				for(int kk=i+2;kk<=nums.size()-1;kk++){
					temp=nums[kk];
					int pos;
					for(pos=kk-1;pos>=i+1;pos--){
						if(nums[pos]>temp)nums[pos+1]=nums[pos];
						else break;
					}
					nums[pos+1]=temp;
				}
				return;
			}
		}
	}
	FOR(i,nums.size()/2){
		temp=nums[i];
		nums[i]=nums[nums.size()-1-i];
		nums[nums.size()-1-i]=temp;
	}
}

void let_31(){
	ifstream fin;
	fin.open("let_31.txt");
	char tempc;
	int value;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums.push_back(value);
	}
	Solution sol;
	sol.nextPermutation(nums);
	FOR(i,nums.size())cout<<nums[i]<<",";
	cout<<endl;
	sol.nextPermutation(nums);
	FOR(i,nums.size())cout<<nums[i]<<",";
	cout<<endl;
	sol.nextPermutation(nums);
	FOR(i,nums.size())cout<<nums[i]<<",";
	cout<<endl;
	sol.nextPermutation(nums);
	FOR(i,nums.size())cout<<nums[i]<<",";
	cout<<endl;
	sol.nextPermutation(nums);
	FOR(i,nums.size())cout<<nums[i]<<",";
	cout<<endl;
	sol.nextPermutation(nums);
	FOR(i,nums.size())cout<<nums[i]<<",";
	cout<<endl;
}