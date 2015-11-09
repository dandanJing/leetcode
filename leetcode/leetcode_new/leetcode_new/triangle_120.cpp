#include"top.h"

int Solution::minimumTotal(vector<vector<int>>& triangle){
	if(triangle.size()==0)return 0;
	if(triangle.size()==1)return triangle[0][0];

	int min_val=0x7fffffff;
	FOR(i,triangle.size()){
		FOR(j,triangle[i].size()){
			if(!i)continue;
			if(j==0)triangle[i][j]+=triangle[i-1][j];
			else if(j==triangle[i].size()-1) triangle[i][j]+=triangle[i-1][j-1];
			else{
				triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
			}
			if(i==triangle.size()-1 && min_val>triangle[i][j]){
				min_val=triangle[i][j];
			}
		}
	}
	return min_val;
}

void let_120(){
	ifstream fin;
	fin.open("let_120.txt");
	char temp;
	int value;
	fin>>temp;
	vector<vector<int>> triangle;
	while(temp!=']'){
		vector<int>cur;
		while(fin.peek()!=']'){
			fin>>temp>>value;
			cur.push_back(value);
		}
		triangle.push_back(cur);
		fin>>temp;
		if(fin.peek()==',')fin>>temp;
	}
	Solution sol;
	cout<<sol.minimumTotal(triangle)<<endl;
}