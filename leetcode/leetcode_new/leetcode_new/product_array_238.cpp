#include"top.h"

//----------!!!问题1：数据多时，受到内存限制，改变成vector试试
int getProductResult(vector<int> nums, int* result, int start_num, int pre_val);
vector<int> Solution::productExceptSelf(vector<int>& nums) {
	vector<int> result;
	int nums_size=nums.size();

	if(nums_size==1)result.push_back(nums[0]);
	else if(nums_size==2){
		result.push_back(nums[1]);
		result.push_back(nums[0]);
	}else if(nums_size>2){
		int* temp=(int *)new(int[nums_size]);

		int multi=nums[0]*nums[1];
		int post_val=getProductResult(nums,temp,2,multi);
		temp[0]=nums[1]*post_val;
		temp[1]=nums[0]*post_val;
		/*FOR(i,nums_size) temp[i]=1;

		FOR(i,nums_size){
			FOR(j,nums_size){
				if(j!=i)temp[j]*=nums[i];
			}
		}*/
	
		FOR(i,nums_size) result.push_back(temp[i]);

		delete temp;
	}

	return result;
}

int getProductResult(vector<int> nums, int* result, int start_num, int pre_val){
	int diff= nums.size()-start_num;
	if(diff == 1){result[start_num]=pre_val;return nums[start_num];}
	else if(diff == 2){
		result[start_num]=pre_val*nums[start_num+1];
		result[start_num+1]=pre_val*nums[start_num];
		return nums[start_num+1]*nums[start_num];
	}
	else if(diff <= 0) return 0;
	else{
		int temp_multi=nums[start_num+1]*nums[start_num];
		int post_val=getProductResult(nums,result,start_num+2,temp_multi*pre_val);
		result[start_num]=pre_val*nums[start_num+1]*post_val;
		result[start_num+1]=pre_val*nums[start_num]*post_val;
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