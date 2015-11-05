#include"top.h"

//----------!!!问题1：数据多时，受到内存限制，改变在本地vector操作
int getProductResult(vector<int>& nums, int start_num, int pre_val);
vector<int> Solution::productExceptSelf(vector<int>& nums) {
	int nums_size=nums.size();
	int num0;

	if(nums_size==1)nums[0]=0;
	else if(nums_size==2){
		num0=nums[0];
		nums[0]=nums[1];
		nums[1]=num0;
	}else if(nums_size>2){
		num0=nums[0];
		int multi=nums[0]*nums[1];
		int post_val=getProductResult(nums,2,multi);
		nums[0]=nums[1]*post_val;
		nums[1]=num0*post_val;
	}

	return nums;
}

int getProductResult(vector<int>& nums, int start_num, int pre_val){
	int diff= nums.size()-start_num;
	int num0,num1;

	if(diff == 1){
		num0=nums[start_num];
		nums[start_num]=pre_val;
		return num0;
	}else if(diff == 2){
		num0=nums[start_num];
		num1=nums[start_num+1];
		nums[start_num]=pre_val*num1;
		nums[start_num+1]=pre_val*num0;
		return num0*num1;
	}else if(diff <= 0) return 0;
	else{
		num0=nums[start_num];
		num1=nums[start_num+1];
		int temp_multi=nums[start_num+1]*nums[start_num];
		int post_val=getProductResult(nums,start_num+2,temp_multi*pre_val);
		nums[start_num]=pre_val*num1*post_val;
		nums[start_num+1]=pre_val*num0*post_val;
		return post_val*temp_multi;
	}
}


void let_238(){
	ifstream fin;
	fin.open("let_238.txt");

	vector<int>nums;
	int value;
	while(!fin.eof()){
		fin>>value;
		nums.push_back(value);
	}

	Solution sol;
	vector<int> result=sol.productExceptSelf(nums);
	FOR(i,result.size()) cout<<result[i]<<",";
	cout<<endl;
}