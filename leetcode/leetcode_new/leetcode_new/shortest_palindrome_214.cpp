#include"top.h"
bool isPalin(string s){
	if(s.size() <= 1) return true;
	for(int i=0; i<s.size()/2; i++){
		if(s[i] != s[s.size()-1-i]) return false;
	}
	return true;
}
string Solution::shortestPalindrome(string s){
	if(s.size()==0) return s;
	if(isPalin(s)) return s;

	int len = s.size();
	string s_rev;
	s_rev.replace(s_rev.begin(),s_rev.end(),s.rbegin(),s.rend());

	int pos = s_rev.find(s[0]);
	while(pos != -1){
		string tmp = s.substr(0,len-pos);
		if(isPalin(tmp)){
			string result = s_rev.substr(0,pos);
			result += s;
			return result;
		}
		pos = s_rev.find(s[0],pos+1);
	}
	return "";
}

void let_214(){
	Solution sol;
	cout<<sol.shortestPalindrome("abcd")<<endl;
	
}