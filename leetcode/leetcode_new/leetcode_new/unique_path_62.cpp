#include"top.h"

int Solution::uniquePaths(int m, int n){
	if(m<=0 || n<=0)return 0;
	vector<vector<int>>path_vec;
	FOR(i,m){
		vector<int>temp;
		FOR(j,n){
			temp.push_back(1);
		}
		path_vec.push_back(temp);
	}
	int posm=m-2,posn=n-2;
	while(posm>=0 && posn>=0){
		for(int i=posn;i>=0;i--){
			path_vec[posm][i]=path_vec[posm][i+1]+path_vec[posm+1][i];
		}
		for(int i=posm-1;i>=0;i--){
			path_vec[i][posn]=path_vec[i][posn+1]+path_vec[i+1][posn];
		}
		posm--;posn--;
	}
	return path_vec[0][0];
}

void let_62(){
	Solution sol;
	cout<<sol.uniquePaths(5,2)<<endl;
}