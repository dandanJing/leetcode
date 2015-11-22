#include"top.h"

vector<int> findAction(vector<int>& nums, int target,int pos1,int pos2){
	vector<int> result;
	int mid;
	if(pos1>pos2)return result;
	else if(pos1==pos2 && nums[pos1]==target)result.push_back(pos1);
	else if(pos1==pos2)return result;
	else{
		mid=(pos1+pos2)/2;
		if(nums[mid]>target){
			result=findAction(nums,target,pos1,mid-1);
		}else if(nums[mid]<target){
			result=findAction(nums,target,mid+1,pos2);
		}else{
			vector<int>temp1=findAction(nums,target,pos1,mid-1);
			vector<int>temp2=findAction(nums,target,mid+1,pos2);
			if(temp1.size() && temp2.size()){
				result.push_back(temp1[0]);
				result.push_back(temp2.back());
			}else if(temp2.size()){
				result.push_back(mid);
				result.push_back(temp2.back());
			}else if(temp1.size()){
				result.push_back(temp1[0]);
				result.push_back(mid);
			}else{
				result.push_back(mid);
			}
		}
	}
	return result;
}
vector<int> Solution::searchRange(vector<int>& nums, int target){
	vector<int> result;
	result=findAction(nums,target,0,nums.size()-1);
	if(result.size()==0){
		result.push_back(-1);
		result.push_back(-1);
	}else if(result.size()==1){
		result.push_back(result[0]);
	}
	return result;
}

void let_34(){
	ifstream fin;
	fin.open("let_34.txt");
	char tempc;
	int value;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>tempc>>value;
		nums.push_back(value);
	}
	Solution sol;
	vector<int> result=sol.searchRange(nums,8);
	FOR(i,result.size())cout<<result[i]<<",";
	cout<<endl;
}

