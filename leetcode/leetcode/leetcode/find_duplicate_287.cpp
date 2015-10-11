#include"top.h"
using namespace std;

int findDuplicateOp(vector<int>& nums,int div_small,int div_middle,int div_large);
class Solution{
public:
	int findDuplicate(vector<int>& nums){
		int div_small=1,div_middle=nums.size()/2,div_large=nums.size()-1;
		while(1){
			if(div_small==div_large) return div_small;
			else if (div_small>div_large) return -1;

			int small_count=0,large_count=0;
			FOR(i,nums.size()){
				int temp=nums[i];
				if(temp>=div_small && temp<=div_middle)small_count++;
				else if(temp>div_middle && temp<=div_large)large_count++;
			}

			if(small_count>div_middle-div_small+1) {
				div_large=div_middle;
				div_middle=(div_middle+div_small)/2;
			}else{
				div_small=div_middle+1;
				div_middle=(div_middle+1+div_large)/2;
			}
		}
		//return findDuplicateOp(nums,1,nums.size()/2,nums.size()-1);
	}
};

void let_287(){
	fstream fin;
	fin.open("let_287.txt");
	Solution sol;
	vector<int> num_vec;
	int temp;
	while(!fin.eof()){
		fin>>temp;
		num_vec.push_back(temp);
	}
	cout<<sol.findDuplicate(num_vec)<<endl;
}

int findDuplicateOp(vector<int>& nums,int div_small,int div_middle,int div_large){
	if(div_small==div_large) return div_small;
	else if (div_small>div_large) return -1;

	int small_count=0,large_count=0;
	FOR(i,nums.size()){
		int temp=nums[i];
		if(temp>=div_small && temp<=div_middle)small_count++;
		else if(temp>div_middle && temp<=div_large)large_count++;
	}
	if(small_count>div_middle-div_small+1) 
		return findDuplicateOp(nums,div_small,(div_middle+div_small)/2,div_middle);
	else 
		return findDuplicateOp(nums,div_middle+1,(div_middle+1+div_large)/2,div_large);
}