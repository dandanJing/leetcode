#include"top.h"

void Solution::sortColors(vector<int>& nums) {
	int pos=0;
	int pos1=-1,pos2=-1,pos3=nums.size();
	int temp;
	while(pos<pos3){
		if(nums[pos]==0){
			if(pos2!=-1){
				nums[pos]=1;
				nums[pos2++]=0;
			}
			pos++;
		}else if(nums[pos]==2){
			temp=nums[--pos3];
			nums[pos3]=2;
			nums[pos]=temp;
		}else{
			if(pos2==-1)pos2=pos;
			pos++;
		}
	}
}

void let_75(){
	ifstream fin;
	fin.open("let_75.txt");
	char tempc;
	int val;
	
	vector<int>nums;
	while(fin.peek()!=']'){
		fin>>tempc>>val;
		nums.push_back(val);
	}
	Solution sol;
	sol.sortColors(nums);
	FOR(i,nums.size())cout<<nums[i]<<",";
	cout<<endl;
}