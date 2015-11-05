#include"top.h"

//---!!!错误1 输入["111","010","111"]，期望1
int Solution::numIslands(vector<vector<char>>& grid){
	int result=0;

	vector<vector<int>>grid_num;
	FOR(i,grid.size()){
		vector<int> temp_vec;
		FOR(j,grid[i].size()){
			temp_vec.push_back(0);
		}
		grid_num.push_back(temp_vec);
	}

	int cur_val;
	int temp;
	std::map<int,int> same_map;
	std::map<int,int>::iterator it;
	FOR(i,grid.size()){
		FOR(j,grid[i].size()){
			if(grid[i][j]=='0' ) continue;

			cur_val=grid_num[i][j];
			if(cur_val == 0) {++result;cur_val=result;grid_num[i][j]=cur_val;}
			
			if(j<grid[i].size()-1 && grid[i][j+1]!='0'){
				temp = grid_num[i][j+1];
				if(temp && temp<cur_val) {
					it = same_map.find(cur_val);
					if(it != same_map.end() && it->second!= temp){
						int min_val = min(it->second,temp);
						int max_val = max(it->second,temp);
						it = same_map.find(max_val);
						while(it != same_map.end() && it->second!= min_val){
							max_val = max(it->second,min_val);
							min_val = min(it->second,min_val);
							it = same_map.find(max_val);
						}
						same_map.insert(pair<int,int>(max_val,min_val));
					}else if(it == same_map.end()){
						same_map.insert(pair<int,int>(cur_val,temp));
					}
					cur_val=temp;
					grid_num[i][j]=cur_val;
				}
				else if(temp>cur_val){
					it = same_map.find(temp);
					if(it != same_map.end() && it->second!= cur_val){
						int min_val = min(it->second,cur_val);
						int max_val = max(it->second,cur_val);
						it = same_map.find(max_val);
						while(it != same_map.end() && it->second!= min_val){
							max_val = max(it->second,min_val);
							min_val = min(it->second,min_val);
							it = same_map.find(max_val);
						}
						same_map.insert(pair<int,int>(max_val,min_val));
					}else{
						same_map.insert(pair<int,int>(temp,cur_val));
					}
					
					grid_num[i][j+1]=cur_val;
				}
				else{grid_num[i][j+1]=cur_val;}
			}
			if(i<grid.size()-1 && grid[i+1][j]!='0'){
				grid_num[i+1][j]=cur_val;
			}
		}
	}
	
	/*FOR(i,grid.size()){
		FOR(j,grid[i].size()){
			printf("%2i,",grid_num[i][j]);
		}
		cout<<endl;
	}*/
	return result-same_map.size();
}

void let_200(){
	vector<vector<char>>grid;
	ifstream fin;
	//let_200.txt 期望输出23
	//let_200_1.txt 期望输出3
	//let_200_2.txt 期望输出125
	fin.open("let_200_2.txt");
	string s;
	while(!fin.eof()){
		getline(fin,s);
		vector<char> temp;
		FOR(i,s.size()-2){
			if(i) temp.push_back(s[i]);
		}
		grid.push_back(temp);
	}
	vector<char> temp1;
	vector<char> temp2;
	vector<char> temp3;
	vector<char> temp4;

	////测试1
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
	temp4.push_back('0');

	grid.push_back(temp1);
	grid.push_back(temp2);
	grid.push_back(temp3);
	grid.push_back(temp4);

	//测试2
	temp1.push_back('1');
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

	//测试3
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