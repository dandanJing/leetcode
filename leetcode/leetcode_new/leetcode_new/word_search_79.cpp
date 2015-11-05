#include"top.h"

bool findString(vector<vector<char>>& board, string word, int word_pos, std::map<int,int>&contain, int cur_i, int cur_j ){
	if(word_pos>=word.size()) return true;
	char cur_c=word[word_pos];

	bool result=false;
	int i_size=board.size();
	std::map<int,int>::iterator it;

	int i_start=max(cur_i-1,0);
	int i_end=min(cur_i+1,i_size-1);
	
	for(int i=i_start;i<=i_end;i++){
		int j_size=board[i].size();
		int j_start=max(cur_j-1,0);
		int j_end=min(cur_j+1,j_size-1);
		if(i!=cur_i) j_start=j_end=cur_j;
		
		for(int j=j_start;j<=j_end;j++){
			if(i==cur_i && j==cur_j) continue;

			it=contain.find(i*j_size+j);
			if(board[i][j]==cur_c && it == contain.end()){
				contain.insert(pair<int,int>(i*j_size+j,1));
				result=findString(board,word,word_pos+1,contain,i,j);
				contain.erase(i*j_size+j);
				if(result) return result;
			}
		}
	}
	return result;
}

bool Solution::exist(vector<vector<char>>& board, string word){
	if(word.size()==0) return true;

	bool result=false;
	FOR(i,board.size()){
		FOR(j,board[i].size()){
			if(board[i][j]==word[0]){
				std::map<int,int>contain;
				contain.insert(pair<int,int>(i*board[i].size()+j,1));

				result=findString(board,word,1,contain,i,j);
				contain.erase(i*board[i].size()+j);
				if(result) return result;
			}
		}
	}
	return result;
}

void let_79(){
	vector<vector<char>> board;
	vector<char> temp1;
	vector<char> temp2;
	vector<char> temp3;
	/*temp1.push_back('a');
	temp1.push_back('a');
	temp1.push_back('a');
	temp1.push_back('a');
	temp2.push_back('a');
	temp2.push_back('a');
	temp2.push_back('a');
	temp2.push_back('a');
	temp3.push_back('a');
	temp3.push_back('a');
	temp3.push_back('a');
	temp3.push_back('a');*/

	temp1.push_back('A');
	temp1.push_back('B');
	temp1.push_back('C');
	temp1.push_back('E');
	temp2.push_back('S');
	temp2.push_back('F');
	temp2.push_back('E');
	temp2.push_back('S');
	temp3.push_back('A');
	temp3.push_back('D');
	temp3.push_back('E');
	temp3.push_back('E');
	board.push_back(temp1);
	board.push_back(temp2);
	board.push_back(temp3);

	Solution sol;
	/*cout<<sol.exist(board,"ABCCED")<<endl;
	cout<<sol.exist(board,"SEE")<<endl;
	cout<<sol.exist(board,"ADEE")<<endl;*/
	cout<<sol.exist(board,"ABCESEEEFS")<<endl;
	/*cout<<sol.exist(board,"aaaaaaaaaaaa")<<endl;*/
}