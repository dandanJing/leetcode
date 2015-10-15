#include"top.h"

vector<vector<int>> findTarget3(int k, int target, int start_num){
	vector<vector<int>> result;
	if(start_num>9) return result;

	if(start_num>target) return result;
	else if(start_num==target && k==1){
		vector<int> vec;
		vec.push_back(target);
		result.push_back(vec);
		return result;
	}else if(start_num==target){
		return result;
	}

	vector<vector<int>>temp=findTarget3(k,target,start_num+1);
	FOR(i,temp.size()){
		vector<int> vec;
		FOR(j,temp[i].size()) vec.push_back(temp[i][j]);
		result.push_back(vec);
	}

	temp=findTarget3(k-1,target-start_num,start_num+1);
	FOR(i,temp.size()){
		vector<int> vec;
		vec.push_back(start_num);
		FOR(j,temp[i].size()) vec.push_back(temp[i][j]);
		result.push_back(vec);
	}
	
	return result;
}

vector<vector<int>> Solution::combinationSum3(int k, int n){
	vector<vector<int>> result=findTarget3(k,n,1);
	return result;
}

void let_216(){
	Solution sol;
	vector<vector<int>> result=sol.combinationSum3(3,9);
	FOR(i,result.size()){
		FOR(j,result[i].size()) cout<<result[i][j]<<" ";
		cout<<endl;
	}
}