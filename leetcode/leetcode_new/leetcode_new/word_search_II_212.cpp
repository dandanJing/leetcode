#include"top.h"

vector<string> Solution::findWords(vector<vector<char>>& board, vector<string>& words){
	vector<string> result;
	Solution sol;
	FOR(i,words.size()){
		if(sol.exist(board,words[i])) result.push_back(words[i]);
	}
	return result;
}

void let_212(){
	vector<vector<char>> board;
	vector<char> temp1;
	vector<char> temp2;
	vector<char> temp3;
	vector<char> temp4;
	temp1.push_back('o');
	temp1.push_back('a');
	temp1.push_back('a');
	temp1.push_back('n');
	temp2.push_back('e');
	temp2.push_back('t');
	temp2.push_back('a');
	temp2.push_back('e');
	temp3.push_back('i');
	temp3.push_back('h');
	temp3.push_back('k');
	temp3.push_back('r');
	temp4.push_back('i');
	temp4.push_back('f');
	temp4.push_back('l');
	temp4.push_back('v');
	board.push_back(temp1);
	board.push_back(temp2);
	board.push_back(temp3);
	board.push_back(temp4);

	vector<string> words;
	words.push_back("pea");
	words.push_back("oath");
	words.push_back("eat");
	words.push_back("rain");

	Solution sol;
	vector<string> result=sol.findWords(board,words);
	FOR(i,result.size()) cout<<result[i]<<",";
	cout<<endl;
}