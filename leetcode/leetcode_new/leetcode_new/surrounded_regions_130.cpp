#include"top.h"

void Solution::solve(vector<vector<char>>& board){
	char c1='O',c2='X';
	if(board.size()<=2)return;
	if(board[0].size()<=2)return;

	vector<vector<bool>>iso;
	FOR(i,board.size()){
		vector<bool>temp;
		FOR(j,board[0].size()){
			temp.push_back(false);
		}
		iso.push_back(temp);
	}
	queue<pair<int,int>> pos_queue;
	for(int j=0;j<board[0].size();j++){
		if(board[0][j]==c1){
			iso[0][j]=true;
			if(board[1][j]==c1)
				pos_queue.push(pair<int,int>(1,j));
		}
		if(board[board.size()-1][j]==c1){
			iso[board.size()-1][j]=true;
			if(board[board.size()-2][j]==c1)
				pos_queue.push(pair<int,int>(board.size()-2,j));
		}
	}
	for(int i=1;i<board.size()-1;i++){
		if(board[i][0]==c1){
			iso[i][0]=true;
			if(board[i][1]==c1)
				pos_queue.push(pair<int,int>(i,1));
		}
		if(board[i][board[0].size()-1]==c1){
			iso[i][board[0].size()-1]=true;
			if(board[i][board[0].size()-2]==c1)
				pos_queue.push(pair<int,int>(i,board[0].size()-2));
		}
	}
	while(pos_queue.size()){
		pair<int,int>temp=pos_queue.front();
		pos_queue.pop();
		if(iso[temp.first][temp.second])continue;
		else{
			iso[temp.first][temp.second]=true;
			if(temp.first-1>=0 && board[temp.first-1][temp.second]==c1 &&!iso[temp.first-1][temp.second])
				pos_queue.push(pair<int,int>(temp.first-1,temp.second));
			if(temp.first+1<board.size() && board[temp.first+1][temp.second]==c1 &&!iso[temp.first+1][temp.second])
				pos_queue.push(pair<int,int>(temp.first+1,temp.second));
			if(temp.second-1>=0 && board[temp.first][temp.second-1]==c1 &&!iso[temp.first][temp.second-1])
				pos_queue.push(pair<int,int>(temp.first,temp.second-1));
			if(temp.second+1<board[0].size() && board[temp.first][temp.second+1]==c1 &&!iso[temp.first][temp.second+1])
				pos_queue.push(pair<int,int>(temp.first,temp.second+1));
		}
	}
	FOR(i,board.size()){
		FOR(j,board[0].size()){
			if(board[i][j]==c1 && !iso[i][j])
				board[i][j]=c2;
		}
	}
}

void let_130(){
	vector<vector<char>> board;
	ifstream fin;
	fin.open("let_130.txt");
	int M,N;fin>>M>>N;
	char cur;
	FOR(i,M){
		vector<char> temp;
		FOR(j,N){
			fin>>cur;
			temp.push_back(cur);
		}
		board.push_back(temp);
	}
	Solution sol;
	sol.solve(board);
	FOR(i,board.size()){
		FOR(j,board[0].size()){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}