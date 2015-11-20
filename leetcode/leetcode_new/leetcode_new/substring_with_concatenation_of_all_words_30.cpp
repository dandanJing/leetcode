#include"top.h"

vector<int> Solution::findSubstring(string s, vector<string>& words) {
	vector<int> result;
	if(words.size()==0) return result;

	int word_size=words[0].size();
	int totalsize=word_size*words.size();
	if(totalsize>s.size()) return result;

	std::map<string,int> str_map;
	std::map<string,int>::iterator it;
	
	FOR(i,words.size()){
		it=str_map.find(words[i]);
		if(it!=str_map.end()){
			it->second++;continue;
		}
		str_map.insert(pair<string,int>(words[i],1));
	}

	FOR(i,s.size()-totalsize+1){
		std::map<string,int> map_cur(str_map);
		int count=words.size();
		string temp;
		int pos_cur=i;
		while(count){
			temp=s.substr(pos_cur,word_size);
			it=map_cur.find(temp);
			if(it==map_cur.end())break;
			else if(it->second==0){
				break;
			}else{
				it->second--;
				count--;
				pos_cur+=word_size;
			}
		}
		if(count==0)result.push_back(i);
	}
	return result;
}

void let_30(){
	Solution sol;
	vector<string> words;
	words.push_back("foo");
	words.push_back("bar");

	vector<int>  result=sol.findSubstring("barfoothefoobarman",words);
	FOR(i,result.size())cout<<result[i]<<",";
	cout<<endl;

	vector<string> words1;
	words1.push_back("word");
	words1.push_back("good");
	words1.push_back("best");
	words1.push_back("good");
	vector<int>  result1=sol.findSubstring("wordgoodgoodgoodbestword",words1);
	FOR(i,result1.size())cout<<result1[i]<<",";
	cout<<endl;
}