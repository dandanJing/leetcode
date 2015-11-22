#include"top.h"

string Solution::convert(string s, int numRows){
	if(numRows==1)return s;

	vector<vector<char>>char_vec;
	FOR(i,numRows){
		vector<char>temp;
		char_vec.push_back(temp);
	}
	int posi=0;int posj=0;
	FOR(i,s.size()){
		char_vec[posi].push_back(s[i]);
		if(posj%(numRows-1)==0){
			if(posi==numRows-1){
				posi--;
				posj++;
			}else posi++;
		}else{
			posi--;
			posj++;
		}
	}
	string result="";
	FOR(i,char_vec.size()){
		FOR(j,char_vec[i].size()){
			result+=char_vec[i][j];
		}
	}
	return result;
}

void let_6(){
	Solution sol;
	cout<<sol.convert("PAYPALISHIRING",3)<<endl;
	cout<<sol.convert("PAYPALISHIRING",4)<<endl;
	cout<<sol.convert("A",1)<<endl;
}