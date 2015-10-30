#include"top.h"

vector<string> Solution::findRepeatedDnaSequences(string s) {
	vector<string> result;
	std::map<string,int> string_map;
	std::map<string,int>::iterator it;
	string temp;
	if(s.size()<10) return result;
	FOR(i,s.size()-9){
		temp = s.substr(i,10);
		it = string_map.find(temp);
		if(it ==string_map.end()){
			string_map.insert(pair<string,int>(temp,1));
		}else{
			it->second++;
			if(it->second==2) result.push_back(temp);
		}
	}
	return result;
}

void let_187(){
	Solution sol;
	string s ="AAAAAAAAAAA";
	vector<string> result = sol.findRepeatedDnaSequences(s);
	FOR(i,result.size()) cout<<result[i]<<endl;
}