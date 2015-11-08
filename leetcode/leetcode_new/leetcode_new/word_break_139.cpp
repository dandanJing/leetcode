#include"top.h"

std::map<string,int> map_s;
int maxsize;
bool findWord(string s,int pos){
	if(pos>=s.size())return true;

	std::map<string,int>::iterator it;
	string temp="";
	for(int i=maxsize;i>0;i--){
		if(i+pos>s.size())return false;
		temp=s.substr(pos,i);
		it=map_s.find(temp);
		if(it!=map_s.end()){
			if(findWord(s,pos+i)) return true;
		}
	}
	return false;
}

bool Solution::wordBreak(string s, vector<string>& wordDict){
	maxsize=0;
	map_s.clear();
	FOR(i,wordDict.size()){
		if(wordDict[i].size()>maxsize)maxsize=wordDict[i].size();
		map_s.insert(pair<string,int>(wordDict[i],1));
	}
	return findWord(s,0);
}

void let_139(){
	/*string s="leetcode";
	vector<string> set;
	set.push_back("leet");
	set.push_back("code");*/

	string s="aaaaaaa";
	vector<string> set;
	set.push_back("aaa");
	set.push_back("aaaa");
	Solution sol;
	cout<<sol.wordBreak(s,set)<<endl;
}