#include"top.h"

vector<vector<int>> Solution::generate(int numRows){
	vector<vector<int>>result;
	FOR(i,numRows){
		vector<int>temp;
		FOR(j,i+1){
			if(!i)temp.push_back(1);
			else if(j==0)temp.push_back(result[i-1][j]);
			else if(j==i)temp.push_back(result[i-1][j-1]);
			else temp.push_back(result[i-1][j-1]+result[i-1][j]);
		}
		result.push_back(temp);
	}
	return result;
}

void let_118(){
	Solution sol;
	vector<vector<int>>result=sol.generate(5);
	FOR(i,result.size()){
		FOR(j,result[i].size()){
			cout<<result[i][j]<<",";
		}
		cout<<endl;
	}
}