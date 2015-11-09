#include"top.h"

vector<int> Solution::getRow(int rowIndex) {
	vector<int>result;
	FOR(i,rowIndex+1){
		result.push_back(1);
		for(int j=i-1;j>0;j--){
			result[j]=result[j]+result[j-1];
		}
	}
	return result;
}

void let_119(){
	Solution sol;
	vector<int>result=sol.getRow(3);
	FOR(i,result.size())cout<<result[i]<<",";
	cout<<endl;
}