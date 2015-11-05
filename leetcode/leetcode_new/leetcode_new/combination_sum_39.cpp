#include"top.h"

vector<vector<int>> findTarget(vector<int>& candidates, int target, int start_num){
	vector<vector<int>> result;
	if(start_num>=candidates.size()) return result;
	
	int temp=candidates[start_num];
	if(temp==target){
		vector<int> vec;
		vec.push_back(target);
		result.push_back(vec);
	}else if((temp<target)){
		for(int i=0;i<=target/temp;i++){
			int new_targ=target-i*temp;
			if(new_targ==0){
				vector<int> vec;
				FOR(k,i) vec.push_back(temp);
				result.push_back(vec);
			}else{
				vector<vector<int>> vec_temp=findTarget(candidates,new_targ,start_num+1);
				FOR(k,vec_temp.size()){
					vector<int> vec;
					FOR(j,i) vec.push_back(temp);
					FOR(j,vec_temp[k].size())vec.push_back(vec_temp[k][j]);
					result.push_back(vec);
				}
			}
		}
	}
	return result;
}

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target){
	//²åÈëÅÅÐò
	FOR(i,candidates.size()){
		int temp=candidates[i];
		int j;
		for(j=i;j>0;j--){
			if(candidates[j-1]>temp)candidates[j]=candidates[j-1];
			else {candidates[j]=temp;break;}
		}
		if(j==0) candidates[j]=temp;
	}
	vector<vector<int>> result=findTarget(candidates,target,0);
	return result;
}

void let_39(){
	vector<int> nums;
	ifstream fin;
	fin.open("let_39.txt");
	int value;
	while(!fin.eof()){
		fin>>value;
		nums.push_back(value);
	}
	Solution sol;
	vector<vector<int>> result=sol.combinationSum(nums,7);
	FOR(i,result.size()){
		FOR(j,result[i].size()) cout<<result[i][j]<<" ";
		cout<<endl;
	}
}