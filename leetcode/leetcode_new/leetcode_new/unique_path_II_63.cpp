#include"top.h"

//[[0,0],[0,1]],ÆÚÍû0
int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
	if(obstacleGrid.size()==0) return 0;

	int m=obstacleGrid.size();
	int n=obstacleGrid[0].size();
	if(m<=0 || n<=0)return 0;
	if(obstacleGrid[m-1][n-1])return 0;
	if(m==1 || n==1){
		FOR(i,m){
			FOR(j,n){
				if(obstacleGrid[i][j])return 0;
			}
		}
		return 1;
	}

	vector<vector<int>>path_vec(obstacleGrid);
	int ii;
	for(ii=m-1;ii>=0;ii--){
		if(path_vec[ii][n-1]){path_vec[ii][n-1]=0;break;}
		else path_vec[ii][n-1]=1;
	}
	FOR(i,ii){
		path_vec[i][n-1]=0;
	}
	int jj;
	for(jj=n-2;jj>=0;jj--){
		if(path_vec[m-1][jj]){path_vec[m-1][jj]=0;break;}
		else path_vec[m-1][jj]=1;
	}
	FOR(i,jj){
		path_vec[m-1][i]=0;
	}
	int posm=m-2,posn=n-2;
	while(posm>=0 && posn>=0){
		for(int i=posn;i>=0;i--){
			if(obstacleGrid[posm][i])path_vec[posm][i]=0;
			else path_vec[posm][i]=path_vec[posm][i+1]+path_vec[posm+1][i];
		}
		for(int i=posm-1;i>=0;i--){
			if(obstacleGrid[i][posn])path_vec[i][posn]=0;
			else path_vec[i][posn]=path_vec[i][posn+1]+path_vec[i+1][posn];
		}
		posm--;posn--;
	}
	return path_vec[0][0];
}

void let_63(){
	vector<vector<int>> obstacleGrid;

	ifstream fin;
	fin.open("let_63.txt");
	char tempc;
	int val;
	fin>>tempc;
	while(tempc!=']'){
		vector<int>temp;
		while(fin.peek()!=']'){
			fin>>tempc>>val;
			temp.push_back(val);
		}
		obstacleGrid.push_back(temp);
		fin>>tempc>>tempc;
	}
	Solution sol;
	cout<<sol.uniquePathsWithObstacles(obstacleGrid)<<endl;
}