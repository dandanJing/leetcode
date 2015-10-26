#include"top.h"

bool Solution::isIsomorphic(string s, string t){
	if(s.size()!=t.size()) return false;

	std::map<char,char> datas;
	std::map<char,char> datat;
	std::map<char,char>::iterator it;
	FOR(i,s.size()){
		it=datas.find(s[i]);
		if(it == datas.end()){
			it=datat.find(t[i]);
			if(it != datat.end()) return false;

			datas.insert(pair<char,char>(s[i],t[i]));
			datat.insert(pair<char,char>(t[i],s[i]));
		}else if(it->second != t[i]){
			return false;
		}
	}
	return true;
}

void let_205(){
	ifstream fin;
	fin.open("let_205.txt");
	string s, t;
	Solution sol;
	while(!fin.eof()){
		fin>>s>>t;
		cout<<sol.isIsomorphic(s,t)<<endl;
	}

}