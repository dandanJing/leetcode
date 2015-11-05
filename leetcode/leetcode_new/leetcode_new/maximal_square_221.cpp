#include"top.h"

bool findSquare(vector<vector<char>>& matrix, int line, int row, int side_len){
	for(int i=line;i<line+side_len;i++){
		for(int j=row;j<row+side_len;j++){
			if(i>=matrix.size()) return false;
			if(matrix[i][j]=='0') return false;
		}
	}
	return true;
}

int Solution::maximalSquare(vector<vector<char>>& matrix) {
	if(!matrix.size()) return 0;
	vector<char> mat0=matrix[0];
	int m,n;
	m=matrix.size();
	n=mat0.size();

	int line=0,row=0;
	int result=0;
	int temp=0;
	int max_side=0;
	while(line<m && row<n){
		char cur_char=matrix[line][row];
		if(cur_char=='1'){
			if(!max_side) max_side++;

			if(row+max_side<n+1 && line+max_side<m+1){
				for(int j=row+1;j<n;j++){
					if(findSquare(matrix,line,row,j-row+1)){
						if(j-row+1>max_side) max_side=j-row+1;
					}else{
						break;
					}
				}
			}
		}
		row++;
		if(row==n){
			row=0;
			line++;
			if(line+max_side-1>=m) break;
		}
	}
	return max_side*max_side;
}

void let_221(){
	vector<vector<char>> mat;
	vector<char> temp1;
	temp1.push_back('1');
	temp1.push_back('1');
	temp1.push_back('1');
	temp1.push_back('1');
	temp1.push_back('1');
	vector<char> temp2;
	temp2.push_back('1');
	temp2.push_back('1');
	temp2.push_back('1');
	temp2.push_back('1');
	temp2.push_back('1');
	vector<char> temp3;
	temp3.push_back('1');
	temp3.push_back('1');
	temp3.push_back('1');
	temp3.push_back('1');
	temp3.push_back('1');
	vector<char> temp4;
	temp4.push_back('1');
	temp4.push_back('1');
	temp4.push_back('1');
	temp4.push_back('1');
	temp4.push_back('1');
	mat.push_back(temp1);
	mat.push_back(temp2);
	mat.push_back(temp3);
	mat.push_back(temp4);

	Solution sol;
	cout<<sol.maximalSquare(mat)<<endl;
}