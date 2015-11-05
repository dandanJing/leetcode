#include"top.h"

///---!!!错误1：[2,-5,-2,-4,3]，期望输出24
//----!!!错误2：[1,0,-1,2,3,-5,-2]，期望60
int Solution::maxProduct(vector<int>& nums){
	if(nums.size()==0) return 0;
	if(nums.size()==1) return nums[0];

	int max_val=0x80000000;
	vector<int> num_vec;
	int nega_count=0;
	int nega_min,nega_max;
	int temp=-1;
	FOR(i,nums.size()){
		if(nums[i]==0){
			if(nega_count && nega_count%2==0){
				if(temp<0 && num_vec.size()) temp=1;
				FOR(j,num_vec.size()) temp*=num_vec[j];
			}else if(nega_count>1){
				if(temp>=0) {num_vec.push_back(temp);}
				int temp1=1;
				for(int j=nega_min+1;j<num_vec.size();j++) temp1*=num_vec[j];
				temp=1;
				for(int j=0;j<nega_max;j++) temp*=num_vec[j];
				temp=max(temp,temp1);
			}
			max_val=max(max_val,temp);
			max_val=max(max_val,0);

			num_vec.clear();
			nega_count=0;
			temp=-1;
		}else if(nums[i]>0){
			if(temp>=0) temp*=nums[i];
			else temp=nums[i];
		}else{
			nega_count++;
			if(temp>=0) {num_vec.push_back(temp);max_val=max(max_val,temp);temp=-1;}
			num_vec.push_back(nums[i]);
			if(nega_count==1) nega_min=num_vec.size()-1;
			else nega_max=num_vec.size()-1;
		}
	}
	
	if(nega_count%2==0){
		if(temp<0 && num_vec.size()) temp=1;
		FOR(j,num_vec.size()) temp*=num_vec[j];
	}else if(nega_count>1){
		if(temp>=0) {num_vec.push_back(temp);}
		int temp1=1;
		for(int j=nega_min+1;j<num_vec.size();j++) temp1*=num_vec[j];
		temp=1;
		for(int j=0;j<nega_max;j++) temp*=num_vec[j];
		temp=max(temp,temp1);
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