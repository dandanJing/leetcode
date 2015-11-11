#include"top.h"

int Solution::lengthOfLastWord(string s){
	string last_word="";
	string temp="";
	FOR(i,s.size()){
		if(s[i]==' '){
			if(temp.size()){
				last_word=temp;
				temp="";
			}
		}else{
			temp+=s[i];
		}
	}
	if(temp.size())return temp.size();
	return last_word.size();
}

void let_58(){
	Solution sol;
	cout<<sol.lengthOfLastWord("a")<<endl;
}