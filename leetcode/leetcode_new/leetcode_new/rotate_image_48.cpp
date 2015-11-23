#include"top.h"

void Solution::rotate(vector<vector<int>>& matrix){
	vector<int>cur_vec;
	FOR(i,matrix.size())cur_vec.push_back(0);

	int imax;
	int pos=0;
	int temp;
	FOR(i,matrix.size()/2){
		imax=matrix.size()-1-i;
		pos=0;
		temp=matrix[i][imax];
		matrix[i][imax]=matrix[i][i];
		for(int j=i+1;j<imax;j++){
			cur_vec[pos++]=matrix[j][imax];
			matrix[j][imax]=matrix[i][j];
		}
		cur_vec[pos++]=matrix[imax][imax];
		matrix[imax][imax]=temp;
		for(int j=imax-1;j>=i;j--){
			temp=cur_vec[imax-1-j];
			cur_vec[imax-1-j]=matrix[imax][j];
			matrix[imax][j]=temp;
		}
		for(int j=imax-1;j>=i;j--){
			temp=cur_vec[imax-1-j];
			cur_vec[imax-1-j]=matrix[j][i];
			matrix[j][i]=temp;
		}
		pos=0;
		for(int j=i+1;j<imax;j++){
			matrix[i][j]=cur_vec[pos++];
		}
	}
}

void let_48(){
	ifstream fin;
	fin.open("let_48.txt");
	char tempc;
	int value;
	vector<vector<int>> matrix;
	fin>>tempc;
	while(tempc!=']'){
		vector<int>temp;
		while(fin.peek()!=']'){
			fin>>tempc>>value;
			temp.push_back(value);
		}
		fin>>tempc>>tempc;
		matrix.push_back(temp);
	}
	Solution sol;
	sol.rotate(matrix);
	FOR(i,matrix.size()){
		FOR(j,matrix[i].size()){
			cout<<matrix[i][j]<<",";
		}
		cout<<endl;
	}
}