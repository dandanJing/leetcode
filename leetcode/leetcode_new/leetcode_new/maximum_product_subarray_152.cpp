#include"top.h"

int Solution::maxProduct(vector<int>& nums){
	if(nums.size()==0) return 0;
	if(nums.size()==1) return nums[0];

	int max_val=0x80000000;
	std::stack<int> num_stack;
	int temp=-1;
	bool is_nega=false;
	FOR(i,nums.size()){
		if(nums[i]==0){
			max_val=max(max_val,temp);
			max_val=max(max_val,0);
			num_stack.empty();
			is_nega=false;
			temp=-1;
		}else if(is_nega){
			if(nums[i]>0){
				if(temp>=0) temp*=nums[i];
				else temp=nums[i];
			}else{
				if(temp>=0) temp*=nums[i];
				else temp=nums[i];

				while(num_stack.size()){
					temp*=num_stack.top();
					num_stack.pop();
				}
				is_nega=false;
			}
		}else{
			if(nums[i]>0){
				if(temp>=0) temp*=nums[i];
				else temp=nums[i];
			}else{
				if(temp>=0) {
					max_val=max(max_val,temp);
					num_stack.push(temp);
					temp=-1;
				}
				is_nega=true;
				num_stack.push(nums[i]);
			}
		}
	}
	max_val=max(max_val,temp);
	return max_val;
}

void let_152(){
	fstream fin;
	fin.open("let_152.txt");
	int value;
	char temp;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.maxProduct(nums)<<endl;
}