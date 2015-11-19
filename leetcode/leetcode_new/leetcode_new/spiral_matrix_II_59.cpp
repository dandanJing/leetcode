#include"top.h"

vector<vector<int>> Solution::generateMatrix(int n){
	vector<vector<int>> result;
	vector<int>temp;
	FOR(i,n)temp.push_back(i);

	FOR(i,n){
		vector<int> cur(temp);
		result.push_back(cur);
	}
	int count=1;
	int xmin,xmax,ymin,ymax;
	xmin=0;xmax=n-1;ymin=0;ymax=n-1;
	while(1){
		for(int i=ymin;i<=ymax;i++) result[xmin][i]=count++;
		for(int i=xmin+1;i<=xmax;i++) result[i][ymax]=count++;
		if(xmax>xmin){
			for(int i=ymax-1;i>=ymin;i--) result[xmax][i]=count++;
		}
		if(ymin<ymax){
			for(int i=xmax-1;i>xmin;i--) result[i][ymin]=count++;
		}
		xmin++;xmax--;ymin++;ymax--;
		if(xmin>xmax || ymin>ymax) break;
	}
	return result;
}

void let_59(){
	Solution sol;
	vector<vector<int>> result=sol.generateMatrix(3);

	FOR(i,result.size()){
		FOR(j,result[i].size()){
			cout<<result[i][j]<<",";
		}
		cout<<endl;
	}
}