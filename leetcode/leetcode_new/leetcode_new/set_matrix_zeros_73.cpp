#include"top.h"

void Solution::setZeroes(vector<vector<int>>& matrix) {
	if(!matrix.size()) return;

	vector<bool> row_vec;
	vector<bool> col_vec;
	FOR(i,matrix.size()){
		row_vec.push_back(false);
	}
	FOR(j,matrix[0].size()){
		col_vec.push_back(false);
	}

	FOR(i,matrix.size()){
		if(row_vec[i])continue;
		FOR(j,matrix[i].size()){
			if(row_vec[i] || col_vec[j]) continue;

			if(matrix[i][j]==0){
				vector<int> change_row;
				vector<int> change_col;
				change_row.push_back(i);
				change_col.push_back(j);
				while(change_row.size() || change_col.size()){
					FOR(ii,change_row.size()){
						int temp_row=change_row[ii];
						if(row_vec[temp_row])continue;
						else{
							row_vec[temp_row]=true;
							FOR(jj,matrix[temp_row].size()){
								if(col_vec[jj]) continue;
								else if(matrix[temp_row][jj]==0){
									change_col.push_back(jj);
								}else{
									matrix[temp_row][jj]=0;
								}
							}
						}
					}
					change_row.clear();
					FOR(jj,change_col.size()){
						int temp_col=change_col[jj];
						if(col_vec[temp_col])continue;
						else{
							col_vec[temp_col]=true;
							FOR(ii,matrix.size()){
								if(row_vec[ii]) continue;
								else if(matrix[ii][temp_col]==0){
									change_row.push_back(ii);
								}else{
									matrix[ii][temp_col]=0;
								}
							}
						}
					}
					change_col.clear();
				}
			}
		}
	}
}

void let_73(){
	ifstream fin;
	fin.open("let_73.txt");
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
	sol.setZeroes(matrix);
	FOR(i,matrix.size()){
		FOR(j,matrix[i].size()){
			cout<<matrix[i][j]<<",";
		}
		cout<<endl;
	}
}