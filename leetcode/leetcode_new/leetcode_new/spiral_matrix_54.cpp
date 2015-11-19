#include"top.h"

vector<int> Solution::spiralOrder(vector<vector<int>>& matrix) {
	vector<int> result;

	int m=matrix.size();
	if(m==0) return result;
	int n=matrix[0].size();
	if(n==0) return result;

	int xmin,xmax,ymin,ymax;
	xmin=0;xmax=m-1;ymin=0;ymax=n-1;
	while(1){
		for(int i=ymin;i<=ymax;i++)result.push_back(matrix[xmin][i]);
		for(int i=xmin+1;i<=xmax;i++) result.push_back(matrix[i][ymax]);
		if(xmax>xmin){
			for(int i=ymax-1;i>=ymin;i--)result.push_back(matrix[xmax][i]);
		}
		if(ymin<ymax){
			for(int i=xmax-1;i>xmin;i--) result.push_back(matrix[i][ymin]);
		}
		xmin++;xmax--;ymin++;ymax--;
		if(xmin>xmax || ymin>ymax) break;
	}
	return result;
}

void let_54(){
	ifstream fin;
	fin.open("let_54.txt");
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
	vector<int> result=sol.spiralOrder(matrix);
	FOR(i,result.size())cout<<result[i]<<",";
	cout<<endl;
}