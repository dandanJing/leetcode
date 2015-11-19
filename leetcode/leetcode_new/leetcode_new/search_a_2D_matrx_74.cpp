#include"top.h"

bool Solution::searchMatrix(vector<vector<int>>& matrix, int target) {
	FOR(i,matrix.size()){
		FOR(j,(matrix[i].size()+1)/2){
			int temp=matrix[i][j];
			if(temp>target && j==0) return false;
			else if(temp>target) break;
			else if(temp==target) return true;

			temp=matrix[i][matrix[i].size()-1-j];
			if(temp<target) break;
			else if(temp==target)return true;
		}
	}
	return false;
}

 void let_74(){
	ifstream fin;
	fin.open("let_74.txt");
	char tempc=' ';
	int value;

	vector<vector<int>>matrix;
	fin>>tempc;
	while(!fin.eof() && fin.peek()!=-1){
		vector<int>temp;
		while(fin.peek()!=']'){
			fin>>tempc>>value;
			temp.push_back(value);
		}
		matrix.push_back(temp);
		fin>>tempc>>tempc;
	}
	Solution sol;
	cout<<sol.searchMatrix(matrix,31)<<endl;
 }