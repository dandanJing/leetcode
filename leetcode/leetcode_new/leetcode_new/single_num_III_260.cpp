#include"top.h"

vector<int> Solution::singleNumber(vector<int>& nums){
	vector<int>result;
	return result;
}
void let_260(){
	ifstream fin;
	fin.open("let_260.txt");

	vector<int>temp;
	int value;
	while(!fin.eof()){
		fin>>value;
		temp.push_back(value);
	}
	Solution sol;
	vector<int>result=sol.singleNumber(temp);

	FOR(i,result.size()) cout<<result[i]<<",";
	cout<<endl;
}