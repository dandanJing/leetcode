#include"top.h"

//---!!!错误1 输入["111","010","111"]，期望1
int Solution::numIslands(vector<vector<char>>& grid){
	int result=0;

	int cur_val;
	int temp;
	std::map<int,vector<int>> same_map;
	std::map<int,vector<int>>::iterator it;
	FOR(i,grid.size()){
		FOR(j,grid[i].size()){
			if(grid[i][j]=='0' ) continue;

			cur_val=grid[i][j];
			if(cur_val-'1' == 0) {++result;cur_val='1'+result;grid[i][j]=cur_val;}
			
			if(j<grid[i].size()-1 && grid[i][j+1]!='0'){
				temp = grid[i][j+1];
				if(temp != '1' && temp<cur_val) {
					it = same_map.find(cur_val);
					bool needInsert=true;
					if(it != same_map.end()){
						FOR(kk,it->second.size()){
							if(it->second[kk]==temp) {needInsert=false;break;}
							int max_val=max(it->second[kk],temp);
							int min_val=min(it->second[kk],temp);
							std::map<int,vector<int>>::iterator next= same_map.find(max_val);
							if(next != same_map.end()){
								FOR(jj,next->second.size()){
									if(next->second[jj]==min_val){needInsert=false;break;}
								}
							}
						}
						if(needInsert){it->second.push_back(temp);}
					}else{
						vector<int> to_insert;
						to_insert.push_back(temp);
						same_map.insert(pair<int,vector<int>>(cur_val,to_insert));
					}
					cur_val=temp;
					grid[i][j]=cur_val;
				}
				else if(temp>cur_val){
					it = same_map.find(temp);
					bool needInsert=true;
					if(it != same_map.end()){
						FOR(kk,it->second.size()){
							if(it->second[kk]==cur_val) {needInsert=false;break;}
							int max_val=max(it->second[kk],cur_val);
							int min_val=min(it->second[kk],cur_val);
							std::map<int,vector<int>>::iterator next= same_map.find(max_val);
							if(next != same_map.end()){
								FOR(jj,next->second.size()){
									if(next->second[jj]==min_val){needInsert=false;break;}
								}
							}
						}
						if(needInsert){it->second.push_back(cur_val);}
					}else{
						vector<int> to_insert;
						to_insert.push_back(cur_val);
						same_map.insert(pair<int,vector<int>>(temp,to_insert));
					}
					
					grid[i][j+1]=cur_val;
				}
				else{grid[i][j+1]=cur_val;}
			}
			if(i<grid.size()-1 && grid[i+1][j]!='0'){
				grid[i+1][j]=cur_val;
			}
		}
	}
	int same_count=0;
	for(it=same_map.begin();it!=same_map.end();it++){
		same_count += it->second.size();
		cout<<it->first-'1'<<"->";
		FOR(j,it->second.size()){
			cout<<it->second[j]-'1'<<",";
		}
		cout<<endl;
	}
	
	FOR(i,grid.size()){
		FOR(j,grid[i].size()){
			if(grid[i][j]=='0')printf("%2i,",grid[i][j]-'0');
			else printf("%2i,",grid[i][j]-'1');
		}
		cout<<endl;
	}
	return result-same_count;
}

void let_200(){
	vector<vector<char>>grid;
	ifstream fin;
	//let_200.txt 期望输出23
	//let_200_1.txt 期望输出3
	fin.open("let_200_1.txt");
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