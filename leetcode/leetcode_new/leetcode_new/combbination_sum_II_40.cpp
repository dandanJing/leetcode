#include"top.h"

vector<vector<int>> findTarget2(vector<int>& candidates, int target, int start_num){
	vector<vector<int>> result;
	if(start_num>=candidates.size()) return result;
	
	int temp=candidates[start_num];
	if(temp==target){
		vector<int> vec;
		vec.push_back(target);
		result.push_back(vec);
	}else if((temp<target)){
		int count=0;
		for(int i=start_num;i<candidates.size();i++){
			if(candidates[i]==temp)count++;
		}
		for(int i=0;i<=count;i++){
			int new_targ=target-i*temp;
			if(new_targ==0){
				vector<int> vec;
				FOR(k,i) vec.push_back(temp);
				result.push_back(vec);
			}else if(new_targ<0) break;
			else{
				vector<vector<int>> vec_temp=findTarget2(candidates,new_targ,start_num+count);
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

vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target){
	FOR(i,candidates.size()){
		int temp=candidates[i];
		int j;
		for(j=i;j>0;j--){
			if(candidates[j-1]>temp)candidates[j]=candidates[j-1];
			else {candidates[j]=temp;break;}
		}
		if(j==0) candidates[j]=temp;
	}
	vector<vector<int>> result=findTarget2(candidates,target,0);
	return result;
}

void let_40(){
	vector<int> nums;
	ifstream fin;
	fin.open("let_39.txt");
	int value;
	while(!fin.eof()){
		fin>>value;
		nums.push_back(value);
	}
	Solution sol;
	vector<vector<int>> result=sol.combinationSum2(nums,8);
	FOR(i,result.size()){
		FOR(j,result[i].size()) cout<<result[i][j]<<" ";
		cout<<endl;
	}
}