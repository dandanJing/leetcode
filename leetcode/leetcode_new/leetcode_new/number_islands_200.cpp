#include"top.h"

//---!!!¥ÌŒÛ1  ‰»Î["111","010","111"]£¨∆⁄Õ˚1
int Solution::numIslands(vector<vector<char>>& grid){
	int result=0;
	queue<int> temp;
	FOR(i,grid.size()){
		FOR(j,grid[i].size()){
			if(grid[i][j]=='2' || grid[i][j]=='0' ) continue;

			++result;
			grid[i][j]='2';
			if(j<grid[i].size()-1 && grid[i][j+1]=='1'){
				temp.push(i);
				temp.push(j+1);
			}if(i<grid.size()-1 && grid[i+1][j]=='1'){
				temp.push(i+1);
				temp.push(j);
			}

			while(temp.size()){
				int cur_i=temp.front();
				temp.pop();
				int cur_j=temp.front();
				temp.pop();
				grid[cur_i][cur_j]='2';

				if(cur_j<grid[cur_i].size()-1 && grid[cur_i][cur_j+1]=='1'){
					temp.push(cur_i);
					temp.push(cur_j+1);
				}
				if(cur_j-1>=0 && grid[cur_i][cur_j-1]=='1'){
					temp.push(cur_i);
					temp.push(cur_j-1);
				}
				if(cur_i<grid.size()-1 && grid[cur_i+1][cur_j]=='1'){
					temp.push(cur_i+1);
					temp.push(cur_j);
				}
			}
		}
	}
	return result;
}

void let_200(){
	vector<vector<char>>grid;
	vector<char> temp1;
	vector<char> temp2;
	vector<char> temp3;
	vector<char> temp4;

	//≤‚ ‘1
	/*temp1.push_back('1');
	temp1.push_back('1');
	temp1.push_back('1');
	temp1.push_back('1');
	temp1.push_back('0');

	temp2.push_back('1');
	temp2.push_back('1');
	temp2.push_back('0');
	temp2.push_back('1');
	temp2.push_back('0');

	temp3.push_back('1');
	temp3.push_back('1');
	temp3.push_back('0');
	temp3.push_back('0');
	temp3.push_back('0');

	temp4.push_back('0');
	temp4.push_back('0');
	temp4.push_back('0');
	temp4.push_back('0');
	temp4.push_back('0');*/

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
	temp4.push_back('1');

	grid.push_back(temp1);
	grid.push_back(temp2);
	grid.push_back(temp3);
	grid.push_back(temp4);*/

	//≤‚ ‘3
	temp1.push_back('1');
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
	grid.push_back(temp3);

	Solution sol;
	cout<<sol.numIslands(grid)<<endl;
}