#include"top.h"

bool Solution::isAnagram(string s, string t){
	std::map<char,int> s_count;
	std::map<char,int>::iterator it;

	if(s.size()!=t.size()) return false;

	FOR(i,s.size()){
		it=s_count.find(s[i]);
		if(it==s_count.end()){
			s_count.insert(pair<char,int>(s[i],1));
		}else{
			it->second++;
		}
	}

	FOR(i,t.size()){
		it=s_count.find(t[i]);
		if(it==s_count.end()){
			return false;
		}else if(it->second) it->second--;
		else return false;
	}
	return true;
}

void let_242(){
	ifstream fin;
	fin.open("let_242.txt");
	int N;fin>>N;
	string s,t;
	Solution sol;
	FOR(i,N){
		fin>>s>>t;
		cout<<"Case "<<i+1<<":";
		cout<<sol.isAnagram(s,t)<<endl;
	}
}