#include"top.h"

bool Solution::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
	if(k<=t){
		int *nums_array=(int *) new int[k+1];
	
		int temp_size=k+1;
		if(nums.size()<k+1)temp_size=nums.size();

		FOR(i,temp_size){
			FOR(j,i){
				int val=nums_array[j]-nums[i];
				if(val<0) val=-val;
				if(val<=t && val>=0) return true;
			}
			nums_array[i]=nums[i];
		}

		for(int i=k+1;i<nums.size();i++){
			for(int j=1;j<k+1;j++){
				int val=nums_array[j]-nums[i];
				if(val<0) val=-val;

				if(val<=t && val>=0) return true;
				else nums_array[j-1]=nums_array[j];
			}
			nums_array[k]=nums[i];
		}
	}else{
		std::map<int,int> num_map;
		std::map<int,int>::iterator it;

		int temp_size=k+1;
		if(nums.size()<k+1)temp_size=nums.size();

		FOR(i,temp_size){
			for(int k=-t;k<=t;k++){
				it=num_map.find(nums[i]+k);
				if(it!=num_map.end()) return true;
			}
			
			num_map.insert(pair<int,int>(nums[i],1));
		}

		for(int i=k+1;i<nums.size();i++){
			num_map.erase(nums[i-k-1]);
			for(int k=-t;k<=t;k++){
				it=num_map.find(nums[i]+k);
				if(it!=num_map.end()) return true;
			}
			num_map.insert(pair<int,int>(nums[i],1));
		}
	}
	return false;
}

void let_220(){
	vector<int> nums;
	ifstream fin;
	fin.open("let_219.txt");
	int value;
	int k;fin>>k;
	while(!fin.eof()){
		fin>>value;
		nums.push_back(value);
	}
	Solution sol;
	cout<<sol.containsNearbyAlmostDuplicate(nums,k,2147483647)<<endl;;
}