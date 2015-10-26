#include"top.h"

//---!!!¥ÌŒÛ1  ‰»Î["111","010","111"]£¨∆⁄Õ˚1
int Solution::numIslands(vector<vector<char>>& grid){
	int result=0;

	int cur_val;
	int temp;
	std::map<int,int> same_map;
	FOR(i,grid.size()){
		FOR(j,grid[i].size()){
			if(grid[i][j]=='0' ) continue;

			cur_val=grid[i][j];
			if(cur_val-'1' == 0) {++result;cur_val='1'+result;grid[i][j]=cur_val;}
			
			if(j<grid[i].size()-1 && grid[i][j+1]!='0'){
				temp = grid[i][j+1];
				if(temp != '1' && temp<cur_val) {same_map.insert(pair<int,int>(cur_val,temp));cur_val=temp;grid[i][j]=cur_val;}
				else if(temp>cur_val){same_map.insert(pair<int,int>(temp,cur_val));grid[i][j+1]=cur_val;}
				else{grid[i][j+1]=cur_val;}
			}if(i<grid.size()-1 && grid[i+1][j]!='0'){
				grid[i+1][j]=cur_val;
			}
		}
	}
	return result-same_map.size();
}

void let_200(){
	vector<vector<char>>grid;
	ifstream fin;
	fin.open("let_200.txt");
	string s;
	while(!fin.eof()){
		getline(fin,s);
		vector<char> temp;
		FOR(i,s.size()-2){
			if(i) temp.push_back(s[i]);
		}
		grid.push_back(temp);
	}
	//vector<char> temp1;
	//vector<char> temp2;
	//vector<char> temp3;
	//vector<char> temp4;

	////≤‚ ‘1
	//temp1.push_back('1');
	//temp1.push_back('1');
	//temp1.push_back('1');
	//temp1.push_back('1');
	//temp1.push_back('0');

	//temp2.push_back('1');
	//temp2.push_back('1');
	//temp2.push_back('0');
	//temp2.push_back('1');
	//temp2.push_back('0');

	//temp3.push_back('1');
	//temp3.push_back('1');
	//temp3.push_back('0');
	//temp3.push_back('0');
	//temp3.push_back('0');

	//temp4.push_back('0');
	//temp4.push_back('0');
	//temp4.push_back('0');
	//temp4.push_back('0');
	//temp4.push_back('0');

	//≤‚ ‘2
	/*temp1.push_back('1');
	temp1.push_back('1');
	temp1.push_back('0');
	temp1.push_back('0');
	temp1.push_back('0');

	temp2.push_back('1');
	temp2.push_back('1');
	temp2.push_back('0');
	temp2.push_back('0');
	temp2.push_back('0');

	temp3.push_back('0');
	temp3.push_back('0');
	temp3.push_back('1');
	temp3.push_back('0');
	temp3.push_back('0');

	temp4.push_back('0');
	temp4.push_back('0');
	temp4.push_back('0');
	temp4.push_back('1');
	temp4.push_back('1');*/

	/*grid.push_back(temp1);
	grid.push_back(temp2);
	grid.push_back(temp3);
	grid.push_back(temp4);*/

	//≤‚ ‘3
	/*temp1.push_back('1');
	temp1.push_back('1');
	temp1.push_back('1');

	temp2.push_back('0');
	temp2.push_back('1');
	temp2.push_back('0');

	temp3.push_back('1');
	temp3.push_back('1');
	temp3.push_back('1');
	
	grid.push_back(temp1);
	grid.push_back(temp2);
	grid.push_back(temp3);*/

	Solution sol;
	cout<<sol.numIslands(grid)<<endl;
}