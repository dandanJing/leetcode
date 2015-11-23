#include"top.h"

int Solution::minPathSum(vector<vector<int>>& grid){

	int m=grid.size();
	int n=grid[0].size();
	if(m<=0 || n<=0)return 0;
	int result=0;
	if(m==1 || n==1){
		FOR(i,m){
			FOR(j,n){
				result+=grid[i][j];
			}
		}
		return result;
	}

	vector<vector<int>>path_vec(grid);
	int ii;
	for(ii=m-2;ii>=0;ii--){
		path_vec[ii][n-1]+=path_vec[ii+1][n-1];
	}
	int jj;
	for(jj=n-2;jj>=0;jj--){
		path_vec[m-1][jj]+=path_vec[m-1][jj+1];
	}

	int posm=m-2,posn=n-2;
	while(posm>=0 && posn>=0){
		for(int i=posn;i>=0;i--){
			path_vec[posm][i]+=min(path_vec[posm][i+1],path_vec[posm+1][i]);
		}
		for(int i=posm-1;i>=0;i--){
			path_vec[i][posn]+=min(path_vec[i][posn+1],path_vec[i+1][posn]);
		}
		posm--;posn--;
	}
	return path_vec[0][0];
}

void let_64(){
	vector<vector<int>> grid;

	ifstream fin;
	fin.open("let_64.txt");
	char tempc;
	int val;
	fin>>tempc;
	while(tempc!=']'){
		vector<int>temp;
		while(fin.peek()!=']'){
			fin>>tempc>>val;
			temp.push_back(val);
		}
		grid.push_back(temp);
		fin>>tempc>>tempc;
	}
	Solution sol;
	cout<<sol.minPathSum(grid)<<endl;
}