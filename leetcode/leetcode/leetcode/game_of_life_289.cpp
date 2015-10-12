<<<<<<< HEAD
#include"top.h"

void Solution::gameOfLife(vector<vector<int>>& board){
	int m=board.size();
	int n=board[0].size();
	//¥Ú”°
	FOR(i,m){
		cout<<endl;
		FOR(j,n) {
			cout<<board[i][j]<<" ";
		}
	}
	vector<vector<int>> board_new;
	FOR(i,m){
		vector<int> temp;
		FOR(j,n){
			int live_count=0,dead_count=0;
			for(int x_pos=i-1;x_pos<=i+1;x_pos++){
				if(x_pos<0 || x_pos>=m) continue;
				for(int y_pos=j-1;y_pos<=j+1;y_pos++){
					if(y_pos>=0 && y_pos<n)
						board[x_pos][y_pos] ? live_count++ : dead_count++;
				}
			}
			if(board[i][j]){
				if(live_count<3) temp.push_back(0);
				else if(live_count>4)temp.push_back(0);
				else temp.push_back(1);
			}else if(live_count==3){
				temp.push_back(1);
			}else{
				temp.push_back(0);
			}
		}
		board_new.push_back(temp);
	}
	FOR(i,m)FOR(j,n)board[i][j]=board_new[i][j];
	cout<<endl<<"------------new board----------"<<endl;
	FOR(i,m){
		cout<<endl;
		FOR(j,n) {
			cout<<board[i][j]<<" ";
		}
	}
	cout<<endl;
}

void let_289(){
	fstream fin;
	fin.open("let_289.txt");
	int n,m;
	fin>>m>>n;
	Solution sol;
	vector<vector<int>> board;
	FOR(i,m){
		vector<int>temp_vec;
		FOR(j,n){
			int temp;
			fin>>temp;
			temp_vec.push_back(temp);
		}
		board.push_back(temp_vec);
	}
	sol.gameOfLife(board);
=======
#include"top.h"

void Solution::gameOfLife(vector<vector<int>>& board){
	int m=board.size();
	int n=board[0].size();
	//¥Ú”°
	FOR(i,m){
		cout<<endl;
		FOR(j,n) {
			cout<<board[i][j]<<" ";
		}
	}
	vector<vector<int>> board_new;
	FOR(i,m){
		vector<int> temp;
		FOR(j,n){
			int live_count=0,dead_count=0;
			for(int x_pos=i-1;x_pos<=i+1;x_pos++){
				if(x_pos<0 || x_pos>=m) continue;
				for(int y_pos=j-1;y_pos<=j+1;y_pos++){
					if(y_pos>=0 && y_pos<n)
						board[x_pos][y_pos] ? live_count++ : dead_count++;
				}
			}
			if(board[i][j]){
				if(live_count<3) temp.push_back(0);
				else if(live_count>4)temp.push_back(0);
				else temp.push_back(1);
			}else if(live_count==3){
				temp.push_back(1);
			}else{
				temp.push_back(0);
			}
		}
		board_new.push_back(temp);
	}
	FOR(i,m)FOR(j,n)board[i][j]=board_new[i][j];
	cout<<endl<<"------------new board----------"<<endl;
	FOR(i,m){
		cout<<endl;
		FOR(j,n) {
			cout<<board[i][j]<<" ";
		}
	}
	cout<<endl;
}

void let_289(){
	fstream fin;
	fin.open("let_289.txt");
	int n,m;
	fin>>m>>n;
	Solution sol;
	vector<vector<int>> board;
	FOR(i,m){
		vector<int>temp_vec;
		FOR(j,n){
			int temp;
			fin>>temp;
			temp_vec.push_back(temp);
		}
		board.push_back(temp_vec);
	}
	sol.gameOfLife(board);
>>>>>>> 194f7f9854ba2b4239e312aded309268c3e9d1d4
}