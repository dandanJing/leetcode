#include"top.h"

void findBarrelSort(vector<int> nums,vector<int> result[], vector<int> base_set[]){
	int base,temp;
	FOR(i,nums.size()){
		base=1;
		while(nums[i]/base>10) base*=10;
		temp=nums[i]/base;
		result[temp].push_back(nums[i]);
		base_set[temp].push_back(base);
	}
}
 void getStringResult(vector<int>*sets,string& result,string pre_fix){
	 for(int i=9;i>=0;i--){
		 if(sets[i].size()==0)continue;
		 char temp=' ';
		 if(i)temp=i+'0';
		 if(sets[i].size()==1){
			 result+=(pre_fix+temp);
		 }else{
			 /*vector<int>* bar_sort=findBarrelSort(sets[i]);
			 getStringResult(bar_sort,result,pre_fix+temp);*/
		 }
	 }
 }


string Solution::largestNumber(vector<int>& nums){
	vector<int>bar_sort[10];
	vector<int>base_set[10];
	findBarrelSort(nums,bar_sort,base_set);
	string result="";
	getStringResult(bar_sort,result,base_set,"");
	return result;
}

void let_179(){
	ifstream fin;
	fin.open("let_179.txt");
	int value;
	char temp;
	vector<int> nums;
	while(fin.peek()!=']'){
		fin>>temp>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.largestNumber(nums)<<endl;
}