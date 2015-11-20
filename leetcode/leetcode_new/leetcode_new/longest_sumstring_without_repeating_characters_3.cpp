#include"top.h"

int Solution::lengthOfLongestSubstring(string s){
	std::map<char,int> char_map;
	std::map<char,int> ::iterator it;
	int count=0,max_count=0;
	FOR(i,s.size()){
		it=char_map.find(s[i]);
		if(it==char_map.end()){
			char_map.insert(pair<char,int>(s[i],i));
			count++;
		}else{
			max_count=max(max_count,count);
			for(int j=i-count;j<it->second;j++){
				char_map.erase(s[j]);
			}
			count=i-it->second;
			it->second=i;
		}
	}
	max_count=max(max_count,count);
	return max_count;
}

void let_3(){
	Solution sol;
	cout<<sol.lengthOfLongestSubstring("abcdfabcbadfetyb")<<endl;
	cout<<sol.lengthOfLongestSubstring("b")<<endl;;
}